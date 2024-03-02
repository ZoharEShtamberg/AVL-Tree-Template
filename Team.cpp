#include "Team.h"

int Team::get_ID() const {
    return this->team_ID;
}

int Team::size() const {
    return contestants.get_size();
}

int Team::get_country_ID() const {
    return countryId;
}

Sport Team::get_sport() const {
    return team_sport;
}

int Team::austerity() {
    if (this->size()%3!=0 || this->size()==0){
        return 0;
    }
    return contestants.get_austerity();
}

int Team::strength() {
    if (this->size()%3!=0 || this->size()==0){ //TODO or size==0;
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
