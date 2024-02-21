#include "../AVLTree.h"
#include <iostream>
class IntComparator {
public:
	int operator()(int a, int b) {
		if (a < b) {
			return -1;
		}
		else if (a > b) {
			return 1;
		}
		else {
			return 0;
		}
	}
};

int main() {
	AVLTree<int, IntComparator> tree;
	tree.insert(5);
	tree.remove(5);
	std::cout<<tree.isCorrect()<<"\n"; 

}
