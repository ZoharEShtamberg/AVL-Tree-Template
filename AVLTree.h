#ifndef AVLTree_H
#define AVLTree_H
template<typename T>
class AVLTree{
	public:
		class node{
			public:
				T key;
				int height;
				node * left;
				node * right;
				node(T k):key(k),height(1),left(nullptr),right(nullptr){}
		};
		AVLTree() : n(0), root(nullptr){}

		~AVLTree(){
			destroy(root);
		}

		void insert(T x){
			root=insertUtil(root, x);
		}

		void remove(T x){
			root=removeUtil(root, x);
		}

		node * search(T x){// do i want to return the node or the key?
			return searchUtil(root,x);
		}


		
	private:
		int n; //number of nodes
		node * root;

		void destroy(node* head){
			if(head==nullptr) return;
			destroy(head->left);
			destroy(head->right);
			delete head;
		}
		node * insertUtil(node * head, T x){
			if(head==nullptr){
				node newNode = new node(x);
				n++; //aloc error wont change n
				return newNode;
			}
			if(x < head->key){
				head->left=insertUtil(head->left, x);
			}
			else if(x > head->key){
				head->right=insertUtil(head->right, x);
			}
			int balance = height(head->left) - height(head->right);
			if(balance ==2){
				//stuff
			}
			else if(balance == -2){
				//stuff
			}
		}
			


		
};
#endif