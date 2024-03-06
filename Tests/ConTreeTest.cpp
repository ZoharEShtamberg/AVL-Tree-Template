//
// Created by Daniella on 02/03/2024.
//
//
// Created by Daniella on 02/03/2024.
//
#define CONTESTANT_TREE_TEST_AMOUNT 5
#include "Olympicsa1.h"

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
/**
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
bool removeContestant(){
    try {
        Team team1 = Team(1, 1, Sport::SWIMMING);
        Contestant con = Contestant(1, 1, Sport::SWIMMING, 1);
        try {
            team1.remove_player(&con);
        } catch (KeyDoesNotExistException&) {
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
        team1.remove_player((&con));
        try {
            team1.remove_player(&con);
        } catch (KeyDoesNotExistException&) {
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
        int powers[9]={4 ,6 ,7 ,15,11 ,10 ,3 ,5 ,2};
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
        if (test_strength==888){
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
        if (team1.strength()!=0 || team1.austerity()!=0){
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
        if (team1.strength()!=0 || team1.austerity()!=0){
            return false;
        }
        return true;
    }catch (const std::exception&){
        return false;
    }
}
**/
int main(){
    Olympics test=Olympics();
    test.add_country(1,0);
    test.add_country(2,0);

    test.add_team(1,1,Sport::SWIMMING);
    int conts[12]={1,2,3,4,10,20,30,40,100,200,300,400};
    int powers[12]={800,700,600,500,80,70,60,50,8, 7 ,6,5};
    for (int i = 0; i < 12; ++i) {
        test.add_contestant(conts[i],1,Sport::SWIMMING,powers[i]);
        test.add_contestant_to_team(1,conts[i]);
    }
    test.add_team(2,2,Sport::SWIMMING);
    int conts2[9]={103 ,102 ,101 ,13 ,12 ,11 ,7 ,6 ,5};
    int powers2[9]={4 ,6 ,7 ,15,11 ,10 ,3 ,5 ,2};
    for (int i = 0; i < 9; ++i) {
        test.add_contestant(conts2[i],2,Sport::SWIMMING,powers2[i]);
        test.add_contestant_to_team(2,conts2[i]);
    }

    printf(" strength 1 is %d\n",test.get_team_strength(1).ans());
    printf(" strength 2 is %d\n",test.get_team_strength(2).ans());
    test.play_match(1,2);
    if(test.get_medals(1).ans()!=1){
        printf("fail play match\n");
    }
    test.add_team(3,1,Sport::SWIMMING);
    for (int i = 0; i < 9; ++i) {
        test.add_contestant(conts2[i],1,Sport::SWIMMING,powers2[i]);
        test.add_contestant_to_team(3,conts2[i]);
    }
    printf("austerity 1 is  %d\n",test.austerity_measures(1).ans());
    printf("austerity 2 is %d\n",test.austerity_measures(2).ans());

    test.unite_teams(1,3);
    printf("new strength is %d\n",test.get_team_strength(1).ans());



    return 0;
}
/**
void pritzzz(){
    bool check= true;

    if(!insertSameContestant()){
        printf("fail test insert same contestant\n");
        check= false;
    } else{
        printf("success test insert same contestant\n");
    }
    if(!getStrength1()){
        printf("fail test get strength1\n");
        check= false;
    }
    else{
        printf("success test get strength1\n");
    }
    if(!getStrength2()){
        printf("fail test get strength 2\n");
        check= false;
    }
    else{
        printf("success test get strength 2\n");
    }
    if(!removeContestant()){
        printf("fail test remove non member contestant\n");
        check= false;
    }
    else{
        printf("success test remove non member contestant\n");
    }
    if(!getStrengthAndAusterityZero()){
        printf("fail test zero if size not div by 3 or 0\n");
        check= false;
    }
    else{
        printf("success test zero if size not div by 3 or 0\n\n");
    }
    if (!removeSameContestant()){
        printf("fail test remove member contestant twice\n");
        check= false;
    }
    else{
        printf("success test remove member contestant twice\n");
    }
    if (check){
        printf("hell yeah");
        return;
    }
    printf("go debug");


}**/