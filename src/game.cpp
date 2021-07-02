#include <iostream>
#include <vector>
#include "../include/game.h"
#include "../include/kenobet.h"
#include "../include/payofftable.h"

using namespace std;

int equal_bet(KenoBet& bet, set_of_spot_t& Rnum, set_of_spot_t& hits)
{
	int cont = 0;
	for (spot_t i : Rnum)
	{
		for (spot_t j : bet.get_spots())
		{
			if (i==j)
			{
				hits.push_back(j);
				cont++;
			}
		}
	}
	return cont;
}

void bet_win(KenoBet& bet, int n_hits, int round, wage_t first_wage)
{
	double multiplier = PAYOFF_TABLE[bet.get_spots_size()][n_hits];

	//double new_wage=(bet.get_wage()-(first_wage/round))+(first_wage/round)*multiplier;
	wage_t new_wage = bet.get_wage()+(first_wage/round)*(multiplier-1);

	bet.set_wage(new_wage);
}
