#ifndef INTERFACE_H
#define INTERFACE_H
#include "../include/kenobet.h"

/* @brief Prints an error message.
 */
void file_error();

/* @brief Prints which file is beeing read
 * @param arg File name as string.
 */
void read_file(char *arg);

/* @brief Prints the rules of the game and the contents of the
 * file(if they are validated).
 * @param arg File name as string.
 * @param rounds number of rounds that the player want to play.
 * @param bet The class that contains all the parameters of the
 * bet.
 */
void rules_file(char *arg, int rounds, KenoBet bet);

/* @brief Prints the events of each round.
 * @param bet The class that contains all the parameters of the
 * bet.
 * @param Rnum Vector that contains the random numbers that
 * were drawn.
 * @param hits Vector that contains the numbers that the player
 * have chosen.
 * @param rodada Contains which round the game is in.
 * @param rounds number of rounds that the player want to play.
 * @param n_hits Quantity of numbers chosen by the player.
 * @param first_wage The credits that were beted.
 */
void game_run_interface(KenoBet bet, set_of_spot_t& Rnum,
                        set_of_spot_t& hits, int n_hits,
                        int rodada, int rounds, wage_t first_wage);

/* @brief Prints the summary of events that happend through the
 * rounds.
 * @param bet The class that contains all the parameters of
 * the bet.
 * @param first_wage The credits that were beted.
 */
void end_game(KenoBet bet, wage_t first_wage);

#endif

