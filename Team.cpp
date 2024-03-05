#include "Team.h"

int Team::get_ID() const {
    return this->team_ID;
}

int Team::size() const {
    return contestants.get_size();
}


Sport Team::get_sport() const {
    return team_sport;
}

int Team::austerity() {
    if (this->size()%3!=0 || size()==0){
        return 0;
    }
    return contestants.get_austerity();
}

int Team::strength() {
    if (this->size()%3!=0 || size()==0){
        return 0;
    }
    return contestants.get_strength();
}

void Team::add_player(Contestant* contestant) {
    contestants.insert(contestant);
}

void Team::remove_player(Contestant* contestant) {
    contestants.remove(contestant);
}

void Team::unite(Team* team) {
    contestants.uniteWith(team->contestants);
    StupidArr<Contestant*> arr=team->contestants.getContestantsArr();   //waste of memory, but its O(n)!
    for (int i = 0; i < arr.size; ++i) {
        arr.arr[i]->remove_from_team(team->team_ID);
        arr.arr[i]->add_to_team(team_ID);
    }
    delete[] arr.arr;
}