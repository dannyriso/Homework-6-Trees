// tree.cc

#include "tree.hh"
#include <iostream>
#include <assert.h>

using namespace std;

// create_tree allocates space for a Tree, then assigns it a key, value, and left and right branches from arguments.
// Then it returns a pointer to the tree.
tree_ptr_t create_tree(const key_t& key, const value_t& value, tree_ptr_t left, tree_ptr_t right) {
	Tree* tree = new Tree;
	tree->key_ = key;
	tree->value_ = value;
	tree->left_ = left;
	tree->right_ = right;
	return tree;
}

// destroy_tree starts from the passed-in node and recursively deletes all its branches before deleting the node itself.
void destroy_tree(tree_ptr_t tree) {
	tree_ptr_t right = tree->right_;
	tree_ptr_t left = tree->left_;
	if(left != nullptr) {
		destroy_tree(left);
	}
	if(right != nullptr) {
		destroy_tree(right);
	}
	delete tree;
	return;
}

// path_to traces the path from a node to a given tree by recursively running through all branches to the left, and then
// all branches to the right, and building the path once the desired key is found.
	// set_found() and get_found() keep track of whether the desired key has been found across calls.
	// build_path() builds and maintains the path across calls.

bool found;
string path;

void set_found(bool new_found) {
	found = new_found;
}
bool get_found() {
	return found;
}

string build_path(char step) {
	path = step + path;
	return path;
}

string path_to(tree_ptr_t tree, key_t key) {
	found = false;
	path = "";
	if(tree == nullptr) {
		return "";
	}
	key_t current = tree->key_;
	tree_ptr_t left = tree->left_;
	tree_ptr_t right = tree->right_;
	if(current == key) {
		set_found(true);
		return "";
	}
	if(left == nullptr and right == nullptr) {
		return "";
	} else {
		auto step = 'L';
		path_to(left, key);
		if(get_found()) {
			path = build_path(step);
			return path;
		}
		step = 'R';
		path_to(right, key);
		if(get_found()) {
			path = build_path(step);
			return path;
		}
	}
	return path;
	assert(get_found());
}

// node_at reads in each letter of the path, and runs recursively for either the right or left tree. When it
// reaches "" (the end of the string), it returns a pointer to the tree there. If at any point, a letter in
// the path isn't 'R' or 'L', or if it leads to an empty node, it returns nullptr.
tree_ptr_t node_at(tree_ptr_t tree, string path) {
	if(path == "") {
		return tree;
	}
	// Splits the path into the direction being immediately followed and the remaining string
	auto step = path[0];
	auto remaining = path.string::substr(1, path.length());
	
	if((step != 'R' and step != 'L') or tree == nullptr) {
		return nullptr;
	}
	if(step == 'L') {
		tree_ptr_t left = node_at(tree->left_, remaining);
		return left;
	}
	if(step == 'R') {
		tree_ptr_t right = node_at(tree->right_, remaining);
		return right;
	}
	return nullptr;
}

