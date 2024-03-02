
#ifndef CONTESTANT_H
#define CONTESTANT_H

#include "wet1util.h"
#include "AVLTree.h"

class Contestant{
private:
	static const int MAX_TEAM_NUM = 3;
    const int contestant_ID;
    const int country_ID;
    Sport sport;
    int strength;
	int teams[MAX_TEAM_NUM];//{-1,-1,-1}; //were do i put thi?
public:
    Contestant(int id, int country,Sport sport, int strength):contestant_ID(id),
                                                              country_ID(country),
                                                              sport(sport),
                                                              strength(strength){for (int & team : teams) {team=-1;}
    };
    int get_ID() const;
    int get_strength() const;
    void set_strength(int input);
    int get_country_ID() const;
    Sport get_sport() const;
    bool add_to_team(int team);//change type
    bool remove_from_team(int team);
    bool is_available() const;
    bool is_in_team(int team) const;

	};

class ContestantIDComparator{
public:
    int operator()(Contestant* a, Contestant* b){
        if (a->get_ID() < b->get_ID()){
            return LESS;
        }
        if (a->get_ID() > b->get_ID()){
            return GREATER;
        }
        return EQUAL;
    }

    int operator()(Contestant* a, const int b){
        if (a->get_ID() < b){
            return LESS;
        }
        if (a->get_ID() > b){
            return GREATER;
        }
        return EQUAL;
    }

    int operator()(const int a, Contestant* b){
        return this->operator()(b, a);
    }

};


class ContestantStrengthComparator{
public:
    int operator()(Contestant *a, Contestant *b){
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