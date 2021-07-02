#ifndef GAME_H
#define GAME_H
#include <random>
#include <vector>
#include <algorithm>
#include "../include/kenobet.h"

class RandEngine {
public:
	RandEngine(spot_t f, spot_t l) : rd{}, mt(rd()), dist(f, l) {};
	~RandEngine() {};

	/* @brief Generates a random value.
	 * @return Value of generated value.
	 */
	spot_t get_num(void) { return dist(mt); }

	/* @brief Generates a list of random value unique to each other.
	 * @param Size of list.
	 * @return A list of all generated values.
	 */
	set_of_spot_t get_unique_list(unsigned int len)
	{
		set_of_spot_t list {};
		while (list.size() < len) {
			auto rn = dist(mt);
			if(std::any_of(list.begin(), list.end(),
			  [rn](spot_t s){return s==rn;}))
				continue;
			list.push_back(rn);
		}
		return list;
	}

private:
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<spot_t> dist;
};

/* @brief Verifies how many and which numbers of the bet are equal to
 * the draws, sending them to a vector.
 * @param bet The class that contains all the parameters of the bet.
 * @param Rnum Vector that contains the random numbers that were drawn.
 * @param hits Vector that will contain the numbers that the player
 * have chosen.
 * @return Returns how many numbers of the bet are equal to the draws.
 */
int equal_bet(KenoBet& bet, set_of_spot_t &Rnum, set_of_spot_t &hits);

/* @brief Do the math of how much credits the player will have after
 * each round.
 * @param bet The class that contains all the parameters of the bet.
 * @param first_wage The credits that were beted.
 * @param Rnum Vector that contains the random numbers that were drawn.
 * @param n_hits Vector that will contain the numbers that the player
 * have chosen.
 * @param round Number of rounds that the player want to play.
 */
void bet_win(KenoBet& bet, int n_hits, int round, wage_t first_wage);

#endif

