#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <vector>
#include <string>
#include "../include/kenobet.h"

/* @brief Checks if a line of spots is valid for use.
 * @param spots String of spots.
 * @return False if there are duplicated, out-of-range
 * or excessive amount of spots; true otherwise.
 */
bool spots_validate(std::string spots);

/* @brief Checks if a bet file is properly formated and
 * is valid for use.
 * @param arg File name as string.
 * @return False if file can't be opened, doesn't match
 * regex or has incorrect spot choices; true otherwise.
 */
bool file_validate(char *arg);

/* @brief Makes a KenoBet out of a bet file.
 * @param arg File name as string.
 * @param kb KenoBet to be modified.
 * @return Number of rounds.
 */
int file_to_kenobet(char *arg, KenoBet& kb);

#endif

