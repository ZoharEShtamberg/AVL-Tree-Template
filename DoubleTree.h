#ifndef DOUBLE_TREE_H
#define DOUBLE_TREE_H
#include "AVLTree.h"
#include "Contestant.h"

class DoubleTree {
	public:
		DoubleTree() : idTree(), strengthTree() {}
		~DoubleTree() = default;
		void insert(Contestant* contestant) {
			idTree.insert(contestant);
			strengthTree.insert(contestant);
		}
		void remove(Contestant* contestant) {
			idTree.remove(contestant);
			strengthTree.remove(contestant);
		}
		Contestant* searchById(int id) const {
			return idTree.search(id);
		}
        bool isInById(int id){
            return idTree.find(id);
        }
		Contestant* getMaxById() const {
			return idTree.getMax()->key;
		}
		Contestant* getMinById() const {
			return idTree.getMin()->key;
		}
		Contestant* getMaxByStrength() const {
			return strengthTree.getMax()->key;
		}
		Contestant* getMinByStrength() const {
			return strengthTree.getMin()->key;
		}
		bool isEmpty() const {
			return idTree.empty();
		}
		int size() const {
			return idTree.size();
		}

	private:
		AVLTree<Contestant*, ContestantIDComparator> idTree;
		AVLTree<Contestant*, ContestantStrengthComparator> strengthTree;
};



#endif //DOUBLE_TREE_H