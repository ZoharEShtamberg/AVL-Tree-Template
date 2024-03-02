#include "Olympicsa1.h"
#include "AVLTree.h"



Olympics::Olympics(){

}

Olympics::~Olympics(){

}
	
StatusType Olympics::add_country(int countryId, int medals){
	return StatusType::FAILURE;
}
	
StatusType Olympics::remove_country(int countryId){
	return StatusType::FAILURE;
}

StatusType Olympics::add_team(int teamId,int countryId,Sport sport){
	return StatusType::FAILURE;
}

StatusType Olympics::remove_team(int teamId){
	return StatusType::FAILURE;
}
	
StatusType Olympics::add_contestant(int contestantId ,int countryId,Sport sport,int strength){
	return StatusType::FAILURE;
}
	
StatusType Olympics::remove_contestant(int contestantId){
	return StatusType::FAILURE;
}
	
StatusType Olympics::add_contestant_to_team(int teamId,int contestantId){

     try {
     if (teamId<=0 || contestantId<=0){
         return StatusType::INVALID_INPUT;
     }
     Contestant* contestant=O_contestants.search(contestantId);
     Team* team=O_teams.search(teamId);
    if (contestant->get_sport()!=team->get_sport() ||
         contestant->get_country_ID()!=team->get_country_ID()||
         contestant->is_in_team(teamId) ||
         !contestant->is_available()){
        return StatusType::FAILURE;
    }
    team->add_player(contestant);
    contestant->add_to_team(teamId);
    }
     catch (KeyDoesNotExistException&){
        return StatusType::FAILURE;
     }
     catch (KeyAlreadyExistsException&){
        return StatusType::FAILURE;
     }
     catch (std::bad_alloc){
         return StatusType::ALLOCATION_ERROR;
     }


     return StatusType::SUCCESS;
}

StatusType Olympics::remove_contestant_from_team(int teamId,int contestantId){

     try {
        if (teamId <= 0 || contestantId <= 0) {
            return StatusType::INVALID_INPUT;
        }
        Contestant* contestant=O_contestants.search(contestantId);
        Team* team=O_teams.search(teamId);
        if (!contestant->is_in_team(teamId)){
            return StatusType::FAILURE;
        }
        team->remove_player(contestant);
        contestant->remove_from_team(teamId);
    }
    catch (KeyDoesNotExistException&){
        return StatusType::FAILURE;
    }
    catch (KeyAlreadyExistsException&){
        return StatusType::FAILURE;
    }

    return StatusType::SUCCESS;
}


StatusType Olympics::update_contestant_strength(int contestantId ,int change){
	return StatusType::FAILURE;
}

output_t<int> Olympics::get_strength(int contestantId){
	return 0;
}

output_t<int> Olympics::get_medals(int countryId){
	return 0;
}

output_t<int> Olympics::get_team_strength(int teamId){
	return 0;
}

StatusType Olympics::unite_teams(int teamId1,int teamId2){
	return StatusType::FAILURE;
}

StatusType Olympics::play_match(int teamId1,int teamId2){
	return StatusType::FAILURE;
}

output_t<int> Olympics::austerity_measures(int teamId){
	return 0;
}



