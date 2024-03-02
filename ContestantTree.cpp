//
// Created by Daniella on 21/02/2024.
//

#include "ContestantTree.h"

//this structure ensures (low size = high size) (low/high size +3 >= size of mid >= low/high size)

void ContestantTree::balance() {
    if (size%3 != 0){
        return;
    }
    //when we get here we balance back by removing from mid 2 correct elements to low and high
    Contestant *temp = mid_group.getMaxById();
    high_group.insert(temp);
    mid_group.remove(temp);
    temp= mid_group.getMinById();
    low_group.insert(temp);
    mid_group.remove(temp);
    update_austerity();
    update_strength();
}

void ContestantTree::update_strength() {
    strength=high_group.getMaxByStrength()->get_strength()
             +mid_group.getMaxByStrength()->get_strength()
             +low_group.getMaxByStrength()->get_strength();
}

int ContestantTree::get_strength() const {
    return this->strength;
}

int ContestantTree::get_austerity() const {
    return this->austerity;
}

void ContestantTree::insert(Contestant* contestant) {
    int id=contestant->get_ID();
    assert(!high_group.isInById(id) &&
           !mid_group.isInById(id) &&
           !low_group.isInById(id));
    mid_group.insert(contestant);
    size++;
    balance();
}
void ContestantTree::remove(Contestant* contestant) {
    int id=contestant->get_ID();
    if (high_group.isInById(id)){
        remove_from_high(contestant);
    }
    if (mid_group.isInById(id)){
        remove_from_mid(contestant);
    }
    if (low_group.isInById(id)){
        remove_from_low(contestant);
    }
    size--;
    balance();
}

void ContestantTree::remove_from_high(Contestant *contestant) {
    high_group.remove(contestant);
    Contestant *temp = low_group.getMaxById();
    mid_group.insert(temp);
    low_group.remove(temp);
}

void ContestantTree::remove_from_mid(Contestant *contestant) { // moves max of low and min of high to mid so that balance works
    mid_group.remove(contestant);
    Contestant *temp = low_group.getMaxById();
    mid_group.insert(temp);
    low_group.remove(temp);
    temp = high_group.getMinById();
    mid_group.insert(temp);
    low_group.remove(temp);
}

void ContestantTree::remove_from_low(Contestant *contestant) {
    high_group.remove(contestant);
    Contestant *temp = low_group.getMaxById();
    mid_group.insert(temp);
    low_group.remove(temp);

}

int ContestantTree::get_size() const {
    assert(mid_group.size()+low_group.size()+high_group.size()==size);
    return this->size;
}
