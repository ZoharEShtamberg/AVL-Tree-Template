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
	//fields
	int n; //number of nodes
	node* root;
	COMP comp;

	//recursive utility functions
	node* insertUtil(node* head, T key);
	node* removeUtil(node* head, T key);
	node* searchUtil(node* head, T key) const;
	void destroy(node* head);

	//general utility functions
	int height(node* head) const {
		 return (head == nullptr) ? -1 : head->height;
	}
	int balanceFactor(node* head) const{
		return (head == nullptr) ? 0 : height(head->left) - height(head->right);
	}
	node* balanceTree(node* head, int balanceFactor);

    // Roll Functions
    Node *rollLeftLeft(Node *node);
    Node *rollLeftRight(Node *node);
    Node *rollRightLeft(Node *node);
    Node *rollRightRight(Node *node);

};
//--------------recursive utility functions--------------//
template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::insertUtil(AVLTree<T, COMP>::node* head, T key) {
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
	return balanceTree(head, balanceFactor(head));
}


template<typename T, typename COMP>
	void AVLTree<T, COMP>::destroy(AVLTree<T, COMP>::node* head) {
		if (head == nullptr) return;
		destroy(head->left);
		destroy(head->right);
		delete head;
	}

//--------------general utility functions--------------//
template<typename T, typename COMP>
typename AVLTree<T, COMP>::node* AVLTree<T, COMP>::balanceTree(AVLTree<T, COMP>::node* head, int balanceFactor) {
	if (balanceFactor > 1) {
		if(balanceFactor(head->left) > -1) {
			return rollLeftLeft(head);
		}
		else {
			return rollLeftRight(head);
		}
	}
	else if (balanceFactor < -1) {
		if(balanceFactor(head->right) > -1) {
			return rollRightLeft(head);
		}
		else {
			return rollRightRight(head);
		}
	}
	return head;
}

//--------------Roll Functions--------------//
#endif
