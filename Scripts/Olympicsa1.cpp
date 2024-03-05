#include "Olympicsa1.h"
#include "AVLTree.h"



Olympics::Olympics(){

}

Olympics::~Olympics(){
    StupidArr<Country*> countries=O_countries.treeToArray();
    StupidArr<Team*> teams=O_teams.treeToArray();
    StupidArr<Contestant*> contestants=O_contestants.treeToArray();
    for (int i=0;i<countries.size;i++){
        delete countries[i];
    }
    for (int i=0;i<teams.size;i++){
        delete teams[i];
    }
    for (int i=0;i<contestants.size;i++){
        delete contestants[i];
    }
    delete[] countries.arr;
    delete[] teams.arr;
    delete[] contestants.arr;

}
	
StatusType Olympics::add_country(int countryId, int medals){
    if (countryId<=0 || medals<0 ){
        return StatusType::INVALID_INPUT;
    }
    try{
        Country *newCountry=new Country(countryId,medals);
        O_countries.insert(newCountry);
    }catch (std::bad_alloc&){
        //TODO?
        return StatusType::ALLOCATION_ERROR;
    } catch (KeyAlreadyExistsException&) {
        return StatusType::FAILURE;

    }
    return StatusType::SUCCESS;
}
	
StatusType Olympics::remove_country(int countryId){
    //TODO test
    if (countryId<=0 ){
        return StatusType::INVALID_INPUT;
    }
    try{
        Country *countryToDelete=O_countries.search(countryId);
        if (countryToDelete->get_num_of_teams()!=0 || countryToDelete->get_num_of_players()!=0){
            return StatusType::FAILURE;
        }
        O_countries.remove(countryToDelete);
        delete countryToDelete;
    }catch (std::bad_alloc&){
        //TODO?
        return StatusType::ALLOCATION_ERROR;
    } catch (KeyDoesNotExistException&) {
        return StatusType::FAILURE;

    }
    return StatusType::SUCCESS;
}

StatusType Olympics::add_team(int teamId,int countryId,Sport sport){
    if (teamId<=0 ||countryId<=0){
        return StatusType::INVALID_INPUT;
    }
    try{
        Country *tempCountry=O_countries.search(countryId);
        Team* newTeam=new Team(teamId, tempCountry, sport);
        O_teams.insert(newTeam);
        tempCountry->add_team();
    }
    catch (KeyDoesNotExistException&){
        return StatusType::FAILURE;
    }
    catch (KeyAlreadyExistsException&){
        return StatusType::FAILURE;
    }
    catch (std::bad_alloc&){
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}

StatusType Olympics::remove_team(int teamId){
    //TODO test
    if (teamId<=0 ){
        return StatusType::INVALID_INPUT;
    }
    try{
        Team *teamToDelete=O_teams.search(teamId);
        if (teamToDelete->size()!=0){
            return StatusType::FAILURE;
        }

        O_teams.remove(teamToDelete);
        teamToDelete->country->remove_team();
        delete teamToDelete;
    }
    catch (std::bad_alloc&){
        return StatusType::ALLOCATION_ERROR;
    }
    catch (KeyDoesNotExistException&) {
        return StatusType::FAILURE;

    }
    return StatusType::SUCCESS;
}
	
StatusType Olympics::add_contestant(int contestantId ,int countryId,Sport sport,int strength){
    if (contestantId<=0 ||countryId<=0 || strength<0){
        return StatusType::INVALID_INPUT;
    }
    try{
        Country *tempCountry=O_countries.search(countryId);
        Contestant *newContestant = new Contestant(contestantId,tempCountry,sport,strength);
        O_contestants.insert(newContestant);
        tempCountry->add_player();
    }
    catch (KeyDoesNotExistException&){
        return StatusType::FAILURE;
    }
    catch (KeyAlreadyExistsException&){
        return StatusType::FAILURE;
    }
    catch (std::bad_alloc&){
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}
	
StatusType Olympics::remove_contestant(int contestantId){
    //TODO test
    if (contestantId<=0 ){
        return StatusType::INVALID_INPUT;
    }
    try{
        Contestant *contestantToDelete=O_contestants.search(contestantId);
        if (contestantToDelete->teams_amount()!=0){
            return StatusType::FAILURE;
        }
        O_contestants.remove(contestantToDelete);
        contestantToDelete->country->remove_player();
    }
    catch (std::bad_alloc&){
        return StatusType::ALLOCATION_ERROR;
    }
    catch (KeyDoesNotExistException&) {
        return StatusType::FAILURE;

    }
    return StatusType::SUCCESS;
}
	
StatusType Olympics::add_contestant_to_team(int teamId,int contestantId){
    if (teamId<=0 || contestantId<=0){
        return StatusType::INVALID_INPUT;
    }
     try {
     Contestant* new_contestant=O_contestants.search(contestantId);
     Team* team=O_teams.search(teamId);
    if (new_contestant->get_sport()!=team->get_sport() ||
            new_contestant->country->get_ID()!=team->country->get_ID()||
            new_contestant->is_in_team(teamId) ||
         !new_contestant->is_available()){
        return StatusType::FAILURE;
    }
    team->add_player(new_contestant);
         new_contestant->add_to_team(teamId);
    }
     catch (KeyDoesNotExistException&){
        return StatusType::FAILURE;
     }
     catch (KeyAlreadyExistsException&){
        return StatusType::FAILURE;
     }
     catch (std::bad_alloc&){
         return StatusType::ALLOCATION_ERROR;
     }
     return StatusType::SUCCESS;
}

StatusType Olympics::remove_contestant_from_team(int teamId,int contestantId){
    //TODO test
    if (teamId <= 0 || contestantId <= 0) {
        return StatusType::INVALID_INPUT;
    }
     try {

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
    if (contestantId<=0){
        return StatusType::INVALID_INPUT;
    }
    try{
        Contestant *temp=O_contestants.search(contestantId);
        return temp->get_strength(); //success
    }
    catch (KeyDoesNotExistException&){
        return StatusType::FAILURE;
    }
    catch (std::bad_alloc&){
        return StatusType::ALLOCATION_ERROR;
    }
}

output_t<int> Olympics::get_medals(int countryId){
    if (countryId<=0){
        return StatusType::INVALID_INPUT;
    }
    try{
        Country *temp=O_countries.search(countryId);
        return temp->get_medals(); //success
    }
    catch (KeyDoesNotExistException&){
        return StatusType::FAILURE;
    }
    catch (std::bad_alloc&){
        return StatusType::ALLOCATION_ERROR;
    }
}

output_t<int> Olympics::get_team_strength(int teamId){
    if (teamId<=0){
        return StatusType::INVALID_INPUT;
    }
    try{
        Team *temp=O_teams.search(teamId);
        return temp->strength(); //success
    }
    catch (KeyDoesNotExistException&){
        return StatusType::FAILURE;
    }
    catch (std::bad_alloc&){
        return StatusType::ALLOCATION_ERROR;
    }
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



