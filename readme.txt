tree.hh, tree.cc, and test_tree.cc work together to make a framework for building the data structure Tree and its
associated functions.

tree.hh declares the four functions - create_tree, destroy_tree, node_at, and path_to - as well as building the structure
and variable types used. tree.cc then defines the functions, and test_tree.cc enters data into them to ensure they work.

create_tree allocates space for the new Tree and makes a pointer to it. It assigns the tree a key_, value_, left_, and
right_ as passed in from the arguments, and then returns the pointer.

destroy_tree deallocates the space using the delete operator. Starting from the tree in the argument, it checks the left
and right nodes. If either one is not nullptr, it calls destroy_tree on the non-empty tree and repeats until it reaches
the end of the branch, at which point it deletes the tree and returns. In this way, all children are deleted until
it reaches the beginning node and deletes that, as well.

path_to recursively runs through the tree starting at the passed-in node until it finds the desired key, then returns
the path as a string of either 'L' or 'R' indicating which branch to follow. To keep track of whether the desired key
has been found across recursive calls, as well as maintain the state of the path, both found and path are declared
outside of the path_to function, as are the helper functions get_found(), set_found(), and build_path(). get_found()
returns the current value of found, representing whether the key has been found yet. set_found() alters found, and is
only used when the key of a current tree is equal to the desired. build_path() takes in a single character as a step,
then adds it to the path and returns the path. Using these, path_to recursively looks through all the branches below
the passed-in, traveling along the left branches first, and returns the path to the desired key. If the desired key is
absent, path_to halts the program with an assert() checking that get_found() is true at the final return, when looking
at the passed-in node again.

node_at follows a path starting at a passed-in tree and following a string of directions either left or right indicating
which branch to recursively call, ending when the string does. It does so by splitting the path into its first character,
immediately indicating which branch to follow, and the rest of the string, which is entered into the recursive calls.
When the first character is "", the end of the string, it returns the current tree, which is passed through the past
iterations until it is returned overall.
