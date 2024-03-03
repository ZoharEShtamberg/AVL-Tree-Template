//
// Created by Daniella on 21/02/2024.
//
#include "Country.h"

void Country::add_player() {
    num_of_players++;
}

void Country::remove_player() {
    num_of_players--;

}

int Country::get_ID() const {
    return this->country_ID;
}
int Country::get_medals() const {
    return this->num_of_medals;
}

void Country::add_medal() {
    this->num_of_medals++;
}

int Country::get_num_of_players() const {
    return this->num_of_players;
}


void Country::add_team() {
    num_of_teams++;
}

void Country::remove_team() {
    num_of_teams--;
}

int Country::get_num_of_teams() const {
    return this->num_of_teams;
}
