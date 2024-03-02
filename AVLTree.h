#ifndef AVLTree_H
#define AVLTree_H
#include <cassert>
#include "Exceptions.h"
#include "StupidArr.h"
#ifndef NDEBUG
#include <vector>
#include <algorithm>
#endif	//NDEBUG

#define LESS -1
#define EQUAL 0
#define GREATER 1

inline int max(int a, int b) { //its better to use std::max
	return a > b ? a : b;
}

//COMP should overload the () operator to compare two Ts
//COMP (T,T) -> int
//Comp(a,b)=-1 if a < b
//Comp(a,b)=0 if a = b
//Comp(a,b)=1 if a > b
template<typename T, typename COMP>
class AVLTree {
public:
	class node {
	public:
		T key;
		int height;
		node* left;
		node* right;
		node(T k) :key(k), height(0), left(nullptr), right(nullptr) {}
	};
	AVLTree() : n(0), root(nullptr), comp() {}

	~AVLTree() {
		destroy(root);
	}

	void insert(T x) {
		root = insertUtil(root, x);
	}

	void remove(T x) {
		root = removeUtil(root, x);
	}
	template <typename K>
	T& search(K x) const {// do i want to return the node or the key?
		return searchUtil(root, x);
	}

	bool find(T x) const {
		try {
			search(x);
			return true;
		}
		catch (KeyDoesNotExistException&) {
			return false;
		}
	}

	int size() const {
		return n;
	}

	bool empty() const {
		return n == 0;
	}

	node* getMax() const {
		node* temp = root;
		if (temp == nullptr) {
			throw EmptyTreeException();
		}
		while (temp->right != nullptr) {
			temp = temp->right;
		}
		return temp;
	}

	node* getMin() const {
		node* temp = root;
		if (temp == nullptr) {
			throw EmptyTreeException();
		}
		while (temp->left != nullptr) {
			temp = temp->left;
		}
		return temp;
	}

	StupidArr<T> treeToArray() const {
		StupidArr<T> result(n);
		treeToArrayUtil(root, result->arr);
		return result;
	}

	void unite(AVLTree<T, COMP>& other) {
		StupidArr<T> mergedArr = mergeArrays(treeToArray(), other.treeToArray());
		node* newRoot = createFullTree(std::ceil(std::log2(mergedArr.size)));
		//insert the merged array into the tree

	}
#ifndef NDEBUG //for testing purposes
	bool isCorrect() {
		std::vector<T> v = vectorizedTree();
		return isBalanced() && std::is_sorted(v.begin(), v.end()) && v.size() == n;
	}
#endif	//NDEBUG


private:
	//fields
	int n; //number of nodes
	node* root;
	COMP comp;

	//recursive utility functions
	node* insertUtil(node* head, T key);
	node* removeUtil(node* head, T key);
	template <typename K>
	T& searchUtil(node* head, K key) const;
	void destroy(node* head);
	T* treeToArrayUtil(node* head, T* result);
	node* createFullTree(int height);

	//general utility functions
	int height(node* head) const {
		return (head == nullptr) ? -1 : head->height;
	}
	int balanceFactor(node* head) const {
		return (head == nullptr) ? 0 : height(head->left) - height(head->right);
	}
	node* balanceTree(node* head, int balanceFactor);

	// Roll Functions
	node* rollLeftLeft(node* node);
	node* rollLeftRight(node* node);
	node* rollRightLeft(node* node);
	node* rollRightRight(node* node);

	//--------------for testing purposes--------------//
#ifndef NDEBUG
	std::vector<T> vectorizedTree();
	void inOrderUtil_test(std::vector<T>& result, node* head);
	bool isBalanced();
	bool isBalancedUtil(node* head);

#endif	//NDEBUG

};
//--------------recursive utility functions--------------//
template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::insertUtil(AVLTree<T, COMP>::node* head, T key) {
	if (head == nullptr) {
		node* newnode = new node(key);
		n++; //alloc error wont change n
		return newnode;
	}
	if (comp(key, head->key) == LESS) {
		head->left = insertUtil(head->left, key);
	}
	else if (comp(key, head->key) == GREATER) {
		head->right = insertUtil(head->right, key);
	}
	else {
		throw KeyAlreadyExistsException();
	}
	head->height = 1 + max(height(head->left), height(head->right));
	return balanceTree(head, balanceFactor(head));
}


template<typename T, typename COMP>
void AVLTree<T, COMP>::destroy(AVLTree<T, COMP>::node* head) {
	if (head == nullptr) return;
	destroy(head->left);
	destroy(head->right);
	delete head;
}

template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::removeUtil(AVLTree<T, COMP>::node* head, T key) {
	if (head == nullptr) {
		throw KeyDoesNotExistException();
	}
	if (comp(key, head->key) == LESS) {
		head->left = removeUtil(head->left, key);
	}
	else if (comp(key, head->key) == GREATER) {
		head->right = removeUtil(head->right, key);
	}
	else {
		//key found
		if (head->left == nullptr || head->right == nullptr) {	//node has one or no children
			node* temp = (head->left != nullptr) ? head->left : head->right;
			if (temp == nullptr) { 		//node has no children
				temp = head;
				head = nullptr;
			}
			else {	//node has one child
				*head = *temp;
			}
			delete temp;
			n--;
		}
		else {  //node has two children
			node* temp = head->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			head->key = temp->key;
			head->right = removeUtil(head->right, temp->key);
		}

	}

	if (head != nullptr) {
		head->height = 1 + max(height(head->left), height(head->right));
		head = balanceTree(head, balanceFactor(head));
	}
	return head;
}

template<typename T, typename COMP>
template<typename K>
T& AVLTree<T, COMP>::searchUtil(AVLTree<T, COMP>::node* head, K key) const {
	if (head == nullptr) {
		throw KeyDoesNotExistException();
	}
	if (comp(key, head->key) == LESS) {
		return searchUtil(head->left, key);
	}
	else if (comp(key, head->key) == GREATER) {
		return searchUtil(head->right, key);
	}
	else {
		return head->key;
	}
}
template<typename T, typename COMP>
T* AVLTree<T, COMP>::treeToArrayUtil(AVLTree<T, COMP>::node* head, T* result) {
	if (head == nullptr) return result;
	result = treeToArrayUtil(head->left, result);
	*result = head->key;
	result++;
	result = treeToArrayUtil(head->right, result);
	return result;
}
template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* createFullTree(int height) {
	if (height == -1) return nullptr;
	node* head = new node(0);
	head->left = createFullTree(height - 1);
	head->right = createFullTree(height - 1);
	return head;
}
//--------------general utility functions--------------//
template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::balanceTree(AVLTree<T, COMP>::node* head, int bf) {
	if (bf > 1) {
		if (balanceFactor(head->left) > -1) {
			return rollLeftLeft(head);
		}
		else {
			return rollLeftRight(head);
		}
	}
	else if (bf < -1) {
		if (balanceFactor(head->right) > -1) {
			return rollRightLeft(head);
		}
		else {
			return rollRightRight(head);
		}
	}
	return head;
}

template<typename T>
StupidArr<T> mergeArrays(StupidArr<T> arr1, StupidArr<T> arr2){	//TODO: make it work with comp
	T* result = new T[size1 + size2];
	int index1 = 0, index2 = 0, resultIndex = 0;
	while (index1 < size1 && index2 < size2) {
		if (arr1[index1] < arr2[index2]) {
			result[resultIndex] = arr1[index1];
			index1++;
		}
		else if (arr1[index1] > arr2[index2]) {
			result[resultIndex] = arr2[index2];
			index2++;
		}
		else {	//means we need to remove the duplicate
			result[resultIndex] = arr1[index1];
			index1++;
			index2++;
		}
		resultIndex++;
	}
	while (index1 < size1) {
		result[resultIndex] = arr1[index1];
		index1++;
		resultIndex++;
	}
	while (index2 < size2) {
		result[resultIndex] = arr2[index2];
		index2++;
		resultIndex++;
	}
	return StupidArr<T>(result, resultIndex);
}
//--------------Roll Functions--------------//
template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::rollLeftLeft(AVLTree<T, COMP>::node* head) {
	assert(head != nullptr && head->left != nullptr);
	node* newHead = head->left;
	head->left = newHead->right;
	newHead->right = head;
	head->height = 1 + max(height(head->left), height(head->right));
	newHead->height = 1 + max(height(newHead->left), height(newHead->right));
	return newHead;
}
template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::rollRightRight(AVLTree<T, COMP>::node* head) {
	assert(head != nullptr && head->right != nullptr);
	node* newHead = head->right;
	head->right = newHead->left;
	newHead->left = head;
	head->height = 1 + max(height(head->left), height(head->right));
	newHead->height = 1 + max(height(newHead->left), height(newHead->right));
	return newHead;
}

template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::rollLeftRight(AVLTree<T, COMP>::node* head) {
	assert(head != nullptr && head->left != nullptr);
	head->left = rollRightRight(head->left);
	return rollLeftLeft(head);
}

template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::rollRightLeft(AVLTree<T, COMP>::node* head) {
	assert(head != nullptr && head->right != nullptr);
	head->right = rollLeftLeft(head->right);
	return rollRightRight(head);
}

#ifndef NDEBUG
//--------------for testing purposes--------------//

template<typename T, typename COMP>
std::vector<T> AVLTree<T, COMP>::vectorizedTree() {
	std::vector<T> result;
	inOrderUtil_test(result, root);
	return result;
}

template<typename T, typename COMP>
void AVLTree<T, COMP>::inOrderUtil_test(std::vector<T>& result, typename AVLTree<T, COMP>::node* head) {
	if (head == nullptr) return;
	inOrderUtil_test(result, head->left);
	result.push_back(head->key);
	inOrderUtil_test(result, head->right);
}

template<typename T, typename COMP>
bool AVLTree<T, COMP>::isBalanced() {
	return isBalancedUtil(root);
}

template<typename T, typename COMP>
bool AVLTree<T, COMP>::isBalancedUtil(typename AVLTree<T, COMP>::node* head) {
	if (head == nullptr) return true;
	int bf = balanceFactor(head);
	if (bf > 1 || bf < -1) return false;
	return isBalancedUtil(head->left) && isBalancedUtil(head->right);
}
#endif  //NDEBUG
#endif // !AVLTree_H
