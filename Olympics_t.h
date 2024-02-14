#ifndef OLYMPICS_T_H
#define OLYMPICS_T_H
#include "AVL.cpp"
#include "Team.h"
#include "Contestant.h"
#include "Country.h"
#include "Scripts/Olympicsa1.h"
#include "Scripts/wet1util.h"

class Olympics_t
{
	public:
		Olympics_t();
		~Olympics_t();
		StatusType add_country(int countryId, int medals);
		StatusType remove_country(int countryId);
		StatusType add_team(int teamId, int countryId, Sport sport);
		StatusType remove_team(int teamId);
		StatusType add_contestant(int contestantId, int countryId, Sport sport, int strength);
		StatusType remove_contestant(int contestantId);
		StatusType add_contestant_to_team(int contestantId, int teamId);
		StatusType remove_contestant_from_team( int teamId, int contestantId);
		StatusType update_contestant_strength(int contestantId, int strength);
		output_t<int> get_strength(int contestantId);
		output_t<int> get_medals(int countryId);
		output_t<int> get_team_strength(int teamId);
		StatusType unite_teams(int teamId1, int teamId2);
		StatusType play_match(int teamId1, int teamId2);
		output_t<int> austerity_measures(int teamId); 

	private:
		AVL<Country> countries;
		AVL<Contestant> contestants;
		AVL<Team> teams;
};
#endif
