//
// Created by Daniella on 02/03/2024.
//
//
// Created by Daniella on 02/03/2024.
//
#define CONTESTANT_TREE_TEST_AMOUNT 5
#include "Team.h"

/**
 * tests:
 * insert same contestant to team
 *
 * strength when size%3=0
 * strength when size%3!=0
 * DOESN'T TEST:
 * COUNTRY/INPUT VALIDITY
 * insert contestant from different country/sport to team
 */

bool insertSameContestant(){
    try {
        Team team1 = Team(1, 1, Sport::SWIMMING);
        Contestant con = Contestant(1, 1, Sport::SWIMMING, 1);
        team1.add_player(&con);
        con.add_to_team(team1.get_ID());
        try {
            team1.add_player(&con);
        } catch (KeyAlreadyExistsException) {
            return true;
        }
        return false;
    }
    catch (const std::exception&){
        return false;
    }
}
bool removeSameContestant(){
    try {
        Team team1 = Team(1, 1, Sport::SWIMMING);
        Contestant con = Contestant(1, 1, Sport::SWIMMING, 1);
        team1.add_player(&con);
        con.add_to_team(team1.get_ID());
        team1.remove_player(&con);
        try {
            team1.remove_player(&con);
        } catch (KeyDoesNotExistException) {
            return true;
        }
        return false;
    }
    catch (const std::exception&){
        return false;
    }
}


bool getStrength1(){
    try{
        Team team1=Team(1,1,Sport::SWIMMING);
        int conts[9]={102 ,101 ,100 ,20 ,16 ,10 ,6 ,4 ,1};
        int powers[9]={4 ,6 ,7 ,11,15 ,10 ,3 ,5 ,2};
        Contestant *contestants[9];
        for (int i = 0; i < 9; ++i) {
            contestants[i]=new Contestant(conts[i],1,Sport::SWIMMING, powers[i]);
            team1.add_player(contestants[i]);
            contestants[i]->add_to_team(1);
        }
        int test_strength=team1.strength();
        if (test_strength==27){
            return true;
        }
        return false;
    }catch (const std::exception&){
        return false;
    }

}

bool getStrength2(){
    try{
        Team team1=Team(1,1,Sport::SWIMMING);
        int conts[12]={1,2,3,4,10,20,30,40,100,200,300,400};
        int powers[12]={800,700,600,500,80,70,60,50,8, 7 ,6,5};
        Contestant *contestants[12];
        for (int i = 0; i < 12; ++i) {
            contestants[i]=new Contestant(conts[i],1,Sport::SWIMMING, powers[i]);
            team1.add_player(contestants[i]);
            contestants[i]->add_to_team(1);
        }
        int test_strength=team1.strength();
        if (test_strength==444){
            return true;
        }
        return false;
    }catch (const std::exception&){
        return false;
    }
}


bool getStrengthAndAusterityZero(){
    try{
        Team team1=Team(1,1,Sport::SWIMMING);
        if (!team1.strength() || !team1.austerity()){
            return false;
        }
        int conts[3]={1,2,3};
        int powers[3]={7 ,6,5};
        Contestant *contestants[3];
        for (int i = 0; i < 3; ++i) {
            contestants[i]=new Contestant(conts[i],1,Sport::SWIMMING, powers[i]);
            team1.add_player(contestants[i]);
            contestants[i]->add_to_team(1);
        }
        int test_strength=team1.strength();
        team1.remove_player(contestants[0]);
        if (!team1.strength() || !team1.austerity()){
            return false;
        }
        return true;
    }catch (const std::exception&){
        return false;
    }
}

int main(){
    bool check;
    check=insertSameContestant();
    check=check&&removeSameContestant();
    check=check&&getStrength1();
    check=check&&getStrength2();
    check=check&&getStrengthAndAusterityZero();
    if (check){
        printf("hell yeah");
        return 0;
    }
    printf("go debug");
    return 0;
}
