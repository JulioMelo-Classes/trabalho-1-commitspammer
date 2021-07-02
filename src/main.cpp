#include <iostream>
#include <vector>
#include "../include/filehandler.h"
#include "../include/game.h"
#include "../include/kenobet.h"
#include "../include/interface.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc<2) 
	{
		file_error();
		return -1;
	}
	RandEngine engine(1, 80);

	KenoBet bet;
	int rounds = file_to_kenobet(argv[1], bet);
	wage_t first_wage = bet.get_wage();

	read_file(argv[1]);

	if(file_validate(argv[1])==false || rounds==-1) 
	{
		file_error();
		return -1;
	}
	
	rules_file(argv[1],rounds,bet);

	for (int i = 0; i < rounds; i++) //numero de rounds
	{
		set_of_spot_t Rnum(engine.get_unique_list(20));
		set_of_spot_t hits;
		sort(Rnum.begin(), Rnum.end());
		int n_hits = equal_bet(bet, Rnum, hits);
		bet_win(bet, n_hits, rounds, first_wage);

		game_run_interface( bet, Rnum, hits, n_hits, (i+1), rounds, first_wage);
		hits.clear();
		Rnum.clear();
	}

	end_game(bet,first_wage);
	return 0;
}
