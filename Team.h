#ifndef TEAM_H
#define TEAM_H
#include "ContestantTree.h"
class Team{
private:
    const int team_ID;
    const int countryId;
    Sport team_sport;
    int strength; //needs to be updated
    int austerity;
    ContestantTree contestants;
public:
    explicit Team(int id, int country, Sport sport) :team_ID(id),
                                                     countryId(country),
                                                     team_sport(sport),
                                                     strength(0),
                                                     austerity(0){};
    ~Team()=default;
    int get_ID() const;
    int get_num_of_players() const;
    bool add_player();
    bool remove_player();
    //TODO: insert,remove (from tree and update player

};

class TeamComparator {
public:
    int operator()(Team* a, Team* b){
        if (a->get_ID() < b->get_ID()){
            return LESS;
        }
        if (a->get_ID() > b->get_ID()){
            return GREATER;
        }
        return EQUAL;
    }
    int operator()(int a, Team* b){
        if (a < b->get_ID()){
            return LESS;
        }
        if (a > b->get_ID()){
            return GREATER;
        }
        return EQUAL;
    }
    int operator()(Team* a, int b){
        return this->operator()(b, a);
    }
};
#endif