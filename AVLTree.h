template<typename T>
class AVLTree{
	public:
		class node{
			public:
				T key;
				int height;
				node * left;
				node * right;
				node(T k){
					height = 1;
					key = k;
					left = NULL;
					right = NULL;
				}
		};
		AVLTree():n(0),root(nullptr){}

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

		void destroy(node * head){
			if(head==nullptr) return;
			destroy(head->left);
			destroy(head->right);
			delete head;
		}


		
};