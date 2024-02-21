#ifndef COUNTRY_H
#define COUNTRY_H
#include "AVLTree.h"
class Country {
private:
	const int country_ID;
	int num_of_medals;
    int num_of_players;
public:
    explicit Country(int id, int medals )  :country_ID(id), num_of_medals(medals) , num_of_players(0){};
    ~Country() = default;
    Country& operator=(const Country&) = delete; //has to because of id ?
    int get_ID() const;
    int get_medals() const;
    void add_medal();
    void add_player(int player_ID);
    void remove_player(int player_ID);
    int get_num_of_players() const;
};

class CountryComparator {
public:
    int operator()(Country &a, Country &b){
        if (a.get_ID()<b.get_ID()){
            return LESS;
        }
        if (a.get_ID()>b.get_ID()){
            return GREATER;
        }
        return EQUAL;
    }
    int operator()(int a, Country &b){
        if (a<b.get_ID()){
            return LESS;
        }
        if (a>b.get_ID()){
            return GREATER;
        }
        return EQUAL;
    }
    int operator()(Country &a,int b){
        if (a.get_ID()<b){
            return LESS;
        }
        if (a.get_ID()>b){
            return GREATER;
        }
        return EQUAL;
    }
};

#endif