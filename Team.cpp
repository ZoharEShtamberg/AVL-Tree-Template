#include "Team.h"

int Team::get_ID() const {
    return this->team_ID;
}

int Team::get_num_of_players() {
    return contestants.get_size();
}