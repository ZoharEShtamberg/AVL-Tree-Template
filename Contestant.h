
#ifndef CONTESTANT_H
#define CONTESTANT_H

#include "./Scripts/wet1util.h"
#include "AVLTree.h"
#include "Country.h"

class Contestant{
private:
	static const int MAX_TEAM_NUM = 3;
    const int contestant_ID;
    Sport sport;
    int strength;
	int teams[MAX_TEAM_NUM]{-1,-1,-1};
public:
    Country *country;
    Contestant(int id, Country* country,Sport sport, int strength):contestant_ID(id),
                                                              sport(sport),
                                                              strength(strength),
                                                              country(country){};
    int get_ID() const;
    int get_strength() const;
    void set_strength(int input);
    Sport get_sport() const;
    bool add_to_team(int team);//change type
    bool remove_from_team(int team);
    bool is_available() const;
    bool is_in_team(int team) const;
    int teams_amount() const;
    void get_teams(int* arr) const;
	};

class ContestantIDComparator{
public:
    int operator()(Contestant* a, Contestant* b) const{
        if (a->get_ID() < b->get_ID()){
            return LESS;
        }
        if (a->get_ID() > b->get_ID()){
            return GREATER;
        }
        return EQUAL;
    }

    int operator()(Contestant* a, const int b) const{
        if (a->get_ID() < b){
            return LESS;
        }
        if (a->get_ID() > b){
            return GREATER;
        }
        return EQUAL;
    }

    int operator()(const int a, Contestant* b) const{
        if (a < b->get_ID()){
            return LESS;
        }
        if (a > b->get_ID()){
            return GREATER;
        }
        return EQUAL;
    }
};


class ContestantStrengthComparator{
public:
    int operator()(Contestant *a, Contestant *b) const{
        if (a->get_strength()==b->get_strength()){
            if(a->get_ID()==b->get_ID()){
                return EQUAL;
            }
            return a->get_ID()<b->get_ID() ? LESS : GREATER;
        }
        if (a->get_strength()>b->get_strength()){
            return GREATER;
        }
        return LESS;
    }
};


#endif