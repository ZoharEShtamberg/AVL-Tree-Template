//
// Created by Daniella on 21/02/2024.
//

#include "ContestantTree.h"

bool ContestantTree::remove(int contestand_ID) {
    //search in low group
    // try{
    // low_group.search(contestand_ID);
    return true;
}

int ContestantTree::get_size() const {
    return mid_group.size()+low_group.size()+high_group.size();
}