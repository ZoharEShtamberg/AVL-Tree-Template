//
// Created by Daniella on 21/02/2024.
//

#include "ContestantTree.h"

//this structure ensures (low size = high size) (low/high size +3 >= size of mid >= low/high size)

void ContestantTree::balance() {
    if (size%3 != 0 || size==0){
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

void ContestantTree::update_austerity() {
    austerity = 1; //TODO: DO DO 21 21 21
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
    if (size<=2){
        mid_group.insert(contestant);
        size++;
        balance();
        return;
    }
    int id=contestant->get_ID();
    Contestant *temp_con;
    if (high_group.isInById(id) ||
           mid_group.isInById(id) ||
           low_group.isInById(id)){
        throw KeyAlreadyExistsException();
    }
    int contestant_id=contestant->get_ID();
    if (contestant_id<mid_group.getMinById()->get_ID()){
        low_group.insert(contestant);
        temp_con=low_group.getMaxById();
        mid_group.insert(temp_con);
        low_group.remove(temp_con);
    } else if(contestant_id>mid_group.getMaxById()->get_ID()){
        high_group.insert(contestant);
        temp_con=high_group.getMinById();
        high_group.remove(temp_con);
        mid_group.insert(temp_con);
    } else{
        mid_group.insert(contestant) ;
    }
    size++;
    balance();
}
void ContestantTree::remove(Contestant* contestant) {
    int id=contestant->get_ID();
    if (!(high_group.isInById(id) ||
        mid_group.isInById(id) ||
        low_group.isInById(id))){
        throw KeyDoesNotExistException();
    }
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
    if (low_group.size()==0){
        return;
    }
    Contestant *temp = low_group.getMaxById();
    mid_group.insert(temp);
    low_group.remove(temp);
    temp = high_group.getMinById();
    mid_group.insert(temp);
    high_group.remove(temp);
}

void ContestantTree::remove_from_low(Contestant *contestant) {
    low_group.remove(contestant);
    Contestant *temp = high_group.getMinById();
    mid_group.insert(temp);
    high_group.remove(temp);

}

int ContestantTree::get_size() const {
    assert(mid_group.size()+low_group.size()+high_group.size()==size);
    return this->size;
}

StupidArr<Contestant*> ContestantTree::getArrById() const {
    StupidArr<Contestant*> low_arr=low_group.idTreeToArray();
    StupidArr<Contestant*> mid_arr=mid_group.idTreeToArray();
    StupidArr<Contestant*> high_arr=high_group.idTreeToArray();
    StupidArr<Contestant*> temp = mergeArrays(low_arr,mid_arr,ContestantIDComparator());
    StupidArr<Contestant*> result = mergeArrays(temp,high_arr,ContestantIDComparator());
    delete[] temp.arr;
    delete[] low_arr.arr;
    delete[] mid_arr.arr;
    delete[] high_arr.arr;
    return result;
}

StupidArr<Contestant*> ContestantTree::getArrByStrength() const {
    StupidArr<Contestant*> low_arr=low_group.strengthTreeToArray();
    StupidArr<Contestant*> mid_arr=mid_group.strengthTreeToArray();
    StupidArr<Contestant*> high_arr=high_group.strengthTreeToArray();
    StupidArr<Contestant*> temp = mergeArrays(low_arr,mid_arr,ContestantStrengthComparator());
    StupidArr<Contestant*> result = mergeArrays(temp,high_arr,ContestantStrengthComparator());
    delete[] temp.arr;
    delete[] low_arr.arr;
    delete[] mid_arr.arr;
    delete[] high_arr.arr;
    return result;
}

void ContestantTree::uniteWith(ContestantTree &other) {
    StupidArr<Contestant*> this_id_arr = getArrById();
    StupidArr<Contestant*> other_id_arr = other.getArrById();
    StupidArr<Contestant*> this_strength_arr = getArrByStrength();
    StupidArr<Contestant*> other_strength_arr = other.getArrByStrength();
    StupidArr<Contestant*> id_arr = mergeArrays(this_id_arr,other_id_arr,ContestantIDComparator());
    StupidArr<Contestant*> strength_arr = mergeArrays(this_strength_arr,other_strength_arr,ContestantStrengthComparator());
    delete[] this_id_arr.arr;
    delete[] other_id_arr.arr;
    delete[] this_strength_arr.arr;
    delete[] other_strength_arr.arr;
    int size = id_arr.size;
    int low_size = size/3;
    int high_size = size/3;
    int mid_size = size - low_size - high_size;
    StupidArr<Contestant*> low_arr = StupidArr<Contestant*>(id_arr.arr, low_size);
    StupidArr<Contestant*> mid_arr = StupidArr<Contestant*>(id_arr.arr+low_size, mid_size);
    StupidArr<Contestant*> high_arr = StupidArr<Contestant*>(id_arr.arr+low_size+mid_size, high_size);
    StupidArr<Contestant*> low_strength_arr = strengthArrFromIdArr(low_arr,strength_arr);
    StupidArr<Contestant*> mid_strength_arr = strengthArrFromIdArr(mid_arr,strength_arr);
    StupidArr<Contestant*> high_strength_arr = strengthArrFromIdArr(high_arr,strength_arr);

}

StupidArr<Contestant*> ContestantTree::strengthArrFromIdArr(StupidArr<Contestant*> id_arr, StupidArr<Contestant*> strength_arr) const {
    StupidArr<Contestant*> result = StupidArr<Contestant*>(id_arr.size);
    int min_id = id_arr[0]->get_ID();
    int max_id = id_arr[id_arr.size-1]->get_ID();
    for(int i=0, j=0; i<strength_arr.size; i++){
        if(strength_arr[i]->get_ID()>=min_id&&strength_arr[i]->get_ID()<=max_id){
            result[j]==strength_arr[i];
            j++;
            assert(j<=id_arr.size);
        }
    }
    return result;
}
