#ifndef TEAM_H
#define TEAM_H
#include "ContestantTree.h"
class Team{
private:
    const int team_ID;
    Sport team_sport;
    ContestantTree contestants;
public:
    Country *country;
    explicit Team(int id, Country* country, Sport sport) :team_ID(id), country(country),team_sport(sport){};
    ~Team()=default;
    int get_ID() const;
    int size() const;
    Sport get_sport() const;
    void add_player(Contestant* contestant);
    void remove_player(Contestant* contestant);
    int austerity();
    int strength();
    void unite(Team* team);

};

class TeamComparator {
public:
    int operator()(Team* a, Team* b) const{
        if (a->get_ID() < b->get_ID()){
            return LESS;
        }
        if (a->get_ID() > b->get_ID()) {
            return GREATER;
        }
        return EQUAL;
    }
    int operator()(int a, Team* b) const{
        if (a < b->get_ID()){
            return LESS;
        }
        if (a > b->get_ID()){
            return GREATER;
        }
        return EQUAL;
    }
    int operator()(Team* a, int b) const{
        return this->operator()(b, a);
    }
};
#endif