#ifndef AVLTree_H
#define AVLTree_H

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
	AVLTree(COMP comparator) : n(0), root(nullptr), comp(comparator) {}

	~AVLTree() {
		destroy(root);
	}

	void insert(T x) {
		root = insertUtil(root, x);
	}

	void remove(T x) {
		root = removeUtil(root, x);
	}

	node* search(T x) {// do i want to return the node or the key?
		return searchUtil(root, x)->key;
	}



private:
	int n; //number of nodes
	node* root;
	COMP comp;

	height(node* head) const{
		head == nullptr ? return -1: return head->height;
	}

	void destroy(node* head) {
		if (head == nullptr) return;
		destroy(head->left);
		destroy(head->right);
		delete head;
	}
	node* insertUtil(node* head, T key) {
		if (head == nullptr) {
			node newNode = new node(key);
			n++; //aloc error wont change n
			return newNode;
		}
		if (comp(key, head->key) = -1) {
			head->left = insertUtil(head->left, key);
		}
		else if (comp(key, head->key) = 1) {
			head->right = insertUtil(head->right, key);
		}
		head->height = 1 + max(height(head->left), height(head->right));
		int balance = height(head->left) - height(head->right);
		if (balance == 2) {
			//fix imbalance, return new head
		}
		else if (balance == -2) {
			//fix imbalance, return new head
		}
	}
	node* removeUtil(node* head, T key) {
		if (head == nullptr) return nullptr;
		if (comp(key, head->key) == 0){

		}
	}
};
#endif