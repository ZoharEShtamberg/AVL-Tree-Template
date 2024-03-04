//
// Created by Daniella on 21/02/2024.
//

#ifndef DS_HW1_CONTESTANTTREE_H
#define DS_HW1_CONTESTANTTREE_H
#include "DoubleTree.h"

class ContestantTree {
private:
    DoubleTree high_group, mid_group, low_group;
    int size;
    int austerity;
    int strength;
    void balance();
    void update_strength();
    void update_austerity(); //TODO
    void remove_from_high(Contestant* contestant);
    void remove_from_mid(Contestant* contestant);
    void remove_from_low(Contestant* contestant);
public:
    ContestantTree():size(0), austerity(0), strength(0){};
    ~ContestantTree()=default;
    void insert(Contestant* contestant); //assumes not in team
    void remove(Contestant* contestant); //assumes in team
    int get_size() const;
    int get_austerity() const;
    int get_strength() const;
    void uniteWith(ContestantTree& other);
    //create three arrays sorted by id, and merge them into one array
    //do the same for the other ContestantTree
    //merge the two arrays into one array
    //change stuff in the contestants to point to the new tree, and update the size, strength and austerity
    //     !! i say "stuff" because there are going to be some edge cases that i need to think about !!
    //hold the array somewhere
    //create three arrays sorted by strength, and merge them into one array
    //do the same for the other ContestantTree
    //merge the two arrays into one array
    //partition the id array into three arrays, by Dannielle's algorithm
    //partition the strength array into three arrays, according to the the partitioning of the id array
    //create three DoubleTrees from the six arrays
    //(Borat voice) "Great success!"

};


#endif //DS_HW1_CONTESTANTTREE_H
