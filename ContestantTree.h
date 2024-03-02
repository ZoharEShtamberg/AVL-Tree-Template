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

};


#endif //DS_HW1_CONTESTANTTREE_H
