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
	for (int i = 99; i >= 0; i--) {
		try {
			tree.remove(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}
	for (int i = 1000; i >= 0; i -= 13) {
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}
	for (int i = 1000; i >= 0; i -= 11) {
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}
	for (int i = 1000; i >= 0; i -= 5) {
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
		CHECK
	}

	for (int i = 0; i < 1300; i += 3) {
		try {
			tree.insert(i);
		}
		catch (std::exception& e) {
		}
	}
	for (int i = 0; i < 1300; i++) {
		try {
			tree.search(i);
			CHECK
		}
		catch (KeyDoesNotExistException& e) {
		}
	}

	StupidArr<int> arr(10000);
	for (int i = 0; i < 10000; i++) {
		arr[i] = i;
	}
	tree.arrayToTree(arr);
	CHECK
	delete[] arr.arr;

	for(int i=0;i<7000;i++){
		try{
			tree.remove(i);
		}
		catch(std::exception& e){
		}
	}
	CHECK
	std::cout << "Size: " << tree.size() << std::endl;
	std::cout << "Height: " << tree.getRoot()->height << std::endl;
	// std::cout<<"Max: "<<tree.getMax()->key<<std::endl;
	// std::cout<<"Min: "<<tree.getMin()->key<<std::endl;
	// std::cout<<"Size: "<<tree.size()<<std::endl;
}
