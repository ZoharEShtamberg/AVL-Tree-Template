//
// Created by Daniella on 21/02/2024.
//

#ifndef DS_HW1_CONTESTANTTREE_H
#define DS_HW1_CONTESTANTTREE_H
#include "AVLTree.h"
#include "Contestant.h"

class ContestantTree {
private:
    AVLTree<Contestant,ContestantIDComparator> high_group;
    AVLTree<Contestant,ContestantIDComparator> mid_group;
    AVLTree<Contestant,ContestantIDComparator> low_group;
    AVLTree<Contestant,ContestantStrengthComparator> high_group_strength;
    AVLTree<Contestant,ContestantStrengthComparator> mid_group_strength;
    AVLTree<Contestant,ContestantStrengthComparator> low_group_strength;
    int size;
    int austerity_measure;
    int strength;
    void update_strength();
    void update_austerity();
public:
    ContestantTree():size(0), austerity_measure(0), strength(0){};
    ~ContestantTree()=default;
    bool insert(int contestand_ID);
    bool remove(int contestand_ID);
    int get_size() const;
};


#endif //DS_HW1_CONTESTANTTREE_H
