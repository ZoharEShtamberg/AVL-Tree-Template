#ifndef TEAM_H
#define TEAM_H
#include "ContestantTree.h"
class Team{
private:
    const int team_ID;
    const int countryId;
    Sport team_sport;
    ContestantTree contestants;
public:
    explicit Team(int id, int country, Sport sport) :team_ID(id), countryId(country),team_sport(sport){};
    ~Team()=default;
    int get_ID() const;
    int size() const;
    Sport get_sport() const;
    void add_player(Contestant* contestant);
    void remove_player(Contestant* contestant);
    int get_country_ID() const;
    int austerity();
    int strength();
    bool unite(Team* team);

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