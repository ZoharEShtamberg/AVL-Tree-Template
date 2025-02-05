//
// Created by Daniella on 21/02/2024.
//
#include "Contestant.h"

int Contestant::get_strength() const {
    return this->strength;
}

void Contestant::set_strength(int input) {
    this->strength=input;
}

int Contestant::get_ID() const {
    return this->contestant_ID;
}

bool Contestant::add_to_team(int team) {
    for (int & i : this->teams){
        if (i==team){
            return false;
        }
    }
    for (int & i : this->teams){
        if (i==-1){
            i=team;
            return true;
        }
    }
    return false;
}

bool Contestant::is_in_team(int team) const {
    for (int id : this->teams) {
        if (id==team){
            return true;
        }
    }
    return false;
}
bool Contestant::remove_from_team(int team) {
    for (int & id : this->teams) {
        if (id==team){
            id = -1;
            return true;
        }
    }
    return false;
}

bool Contestant::is_available() const {
    for (int team : this->teams) {
        if (team==-1)
            return true;
    }
    return false;
}


Sport Contestant::get_sport() const {
    return this->sport;
}

int Contestant::teams_amount() const {
    int counter=0;
    for (int team : this->teams) {
        if (team!=-1)
            counter++;
    }
    return counter;
}

void Contestant::get_teams(int* arr) const {
    int i=0;
    for (int team : this->teams) {
        arr[i]=team;
        i++;

    }
}