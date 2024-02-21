//
// Created by Daniella on 21/02/2024.
//
#include "Contestant.h"

int Contestant::get_strength() const {
    return this->strength;
}

int Contestant::get_ID() const {
    return this->contestant_ID;
}

bool Contestant::add_to_team(int team) {
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

int Contestant::get_country_ID() const {
    return this->country_ID;
}

Sport Contestant::get_sport() const {
    return this->sport;
}