#ifndef COUNTRY_H
#define COUNTRY_H
#include "AVLTree.h"
class Country {
private:
	const int country_ID;
	int num_of_medals;
    int num_of_players;
    int num_of_teams;
public:
    explicit Country(int id, int medals )  :country_ID(id), num_of_medals(medals) , num_of_players(0), num_of_teams(0){};
    ~Country() = default;
    Country& operator=(const Country&) = delete; //has to because of id ?
    int get_ID() const;
    int get_medals() const;
    void add_medal();
    void add_player();
    void remove_player();
    void add_team();
    void remove_team();
    int get_num_of_players() const;
    int get_num_of_teams() const;
};

class CountryComparator {
public:
    int operator()(Country *a, Country *b) const{
        if (a->get_ID()<b->get_ID()){
            return LESS;
        }
        if (a->get_ID()>b->get_ID()){
            return GREATER;
        }
        return EQUAL;
    }
    int operator()(int a, Country *b) const{
        if (a<b->get_ID()){
            return LESS;
        }
        if (a>b->get_ID()){
            return GREATER;
        }
        return EQUAL;
    }
    int operator()(Country *a,int b) const{
        if (a->get_ID()<b){
            return LESS;
        }
        if (a->get_ID()>b){
            return GREATER;
        }
        return EQUAL;
    }
};

#endif