// test_tree.cc tests the tree.cc file by creating and deleting trees,
// filling them with test data, and testing the public functions.

#include "tree.cc"

int main() {
	// Test create_tree
	tree_ptr_t tree1 = create_tree(-3, 1);
	tree_ptr_t tree2 = create_tree(2, 2);
	tree_ptr_t tree3 = create_tree(-5, 3, tree1, tree2);
	tree_ptr_t tree4 = create_tree(7, 4);
	tree_ptr_t tree5 = create_tree(-4, 5, tree4, tree3);
	tree_ptr_t tree6 = create_tree(8, 6);
	tree_ptr_t tree7 = create_tree(2, 7, tree5, tree6);
	
	// Test destroy_tree
	destroy_tree(tree1);

	// Test path_to
	assert(path_to(tree7, -5) == "LR");
	assert(path_to(tree7, 2) == "");
	assert(path_to(tree3, 2) == "R");

	// Test node_at
	assert(node_at(tree7, "LRL") == tree1);
	assert(node_at(tree7, "LRRA") == nullptr);
	assert(node_at(tree3, "RL") == nullptr);

	// Clear space
	destroy_tree(tree7);

	return 0;
}
