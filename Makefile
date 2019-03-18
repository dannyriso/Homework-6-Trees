COMPILE = g++ -std=c++17
DEBUG_FLAG = -g
WARNINGS = -Wall -Wextra -pedantic

tree_out : test_tree.cc
	$(COMPILE) $(DEBUG_FLAG) $(WARNINGS) test_tree.cc -o out

clean:
	rm tree.cc tree.hh tree.test_tree
