#include "../AVLTree.h"
#include <iostream>
#define CHECK assert(tree.isCorrect());
class IntComparator {
public:
	int operator()(int a, int b) {
		if (a < b) {
			return LESS;
		}
		else if (a > b) {
			return GREATER;
		}
		else {
			return EQUAL;
		}
	}
};

int main() {
	AVLTree<int, IntComparator> tree;
	for (int i = 0; i < 100; i++) {
		tree.insert(i);
		CHECK
	}
	std::cout<<"Size: "<<tree.size()<<std::endl;
	std::cout<<"removing"<<std::endl;
	for (int i = 99; i>=0; i--) {
		tree.remove(i);
		CHECK
	}
	// std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	// std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	std::cout<<"Size: "<<tree.size()<<std::endl;
	std::cout<<"adding back:"<<std::endl;
		for (int i = 1000; i >= 0; i-=13) {
		tree.insert(i);
		CHECK
	}
	std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	std::cout<<"Size: "<<tree.size()<<std::endl;

	std::cout<<"adding some more"<<std::endl;
	for (int i = 1000; i >= 0; i-=11) {
		tree.insert(i);
		CHECK
	}
	std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	std::cout<<"Size: "<<tree.size()<<std::endl;
	std::cout<<"adding some more"<<std::endl;
	for (int i = 1000; i >= 0; i-=5) {
		tree.insert(i);
		CHECK
	}
	std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	std::cout<<"Size: "<<tree.size()<<std::endl;

	std::cout<<"adding some more"<<std::endl;
	for (int i = 0; i < 1300; i+=3) {
		tree.insert(i);
		CHECK
	}
	std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	std::cout<<"Size: "<<tree.size()<<std::endl;

	// std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	// std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	// std::cout<<"Size: "<<tree.size()<<std::endl;
}
