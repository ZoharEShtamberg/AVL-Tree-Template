#include "../AVLTree.h"
#include <iostream>
#define CHECK assert(tree.isCorrect());
class IntComparator {
public:
	int operator()(int a, int b) const {
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
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}
	std::cout << "Size: " << tree.size() << std::endl;
	std::cout << "removing" << std::endl;
	for (int i = 99; i >= 0; i--) {
		try {
			tree.remove(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}
	// std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	// std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	std::cout << "Size: " << tree.size() << std::endl;
	std::cout << "adding back:" << std::endl;
	for (int i = 1000; i >= 0; i -= 13) {
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}
	std::cout << "Max: " << tree.getMax()->key << std::endl;
	std::cout << "Min: " << tree.getMin()->key << std::endl;
	std::cout << "Size: " << tree.size() << std::endl;

	std::cout << "adding some more" << std::endl;
	for (int i = 1000; i >= 0; i -= 11) {
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}
	std::cout << "Max: " << tree.getMax()->key << std::endl;
	std::cout << "Min: " << tree.getMin()->key << std::endl;
	std::cout << "Size: " << tree.size() << std::endl;
	std::cout << "adding some more" << std::endl;
	for (int i = 1000; i >= 0; i -= 5) {
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}
	std::cout << "Max: " << tree.getMax()->key << std::endl;
	std::cout << "Min: " << tree.getMin()->key << std::endl;
	std::cout << "Size: " << tree.size() << std::endl;

	std::cout << "adding some more" << std::endl;
	for (int i = 0; i < 1300; i += 3) {
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
	}
	for (int i = 0; i < 1300; i++) {
		try {
			std::cout << tree.search(i)->key << " found" << std::endl;
			CHECK
		}
		catch (KeyDoesNotExistException& e) {
			std::cout << i << " not found" << std::endl;
		}
	}
	std::cout << "Max: " << tree.getMax()->key << std::endl;
	std::cout << "Min: " << tree.getMin()->key << std::endl;
	std::cout << "Size: " << tree.size() << std::endl;

	// std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	// std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	// std::cout<<"Size: "<<tree.size()<<std::endl;
}
