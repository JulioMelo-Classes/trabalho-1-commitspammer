#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "../include/kenobet.h"
#include "../include/filehandler.h"

using namespace std;

bool spots_validate(string spots)
{
	stringstream ss;
	ss << spots;
	spot_t x;
	set_of_spot_t list {};
	while (ss >> ws >> x) {
		if (x < 1 || x > 80) {
			return false;
		} else if (std::any_of(list.begin(), list.end(),
		          [x](int i){return i==x;})) {
			return false;
		} else if (list.size() > 15) {
			return false;
		}
		list.push_back(x);
	}
	return true;
}

bool file_validate(char *arg)
{
	fstream file;
	file.open(arg);
	if (!file) {
		return false;
	}

	string wage, rounds, spots;
	getline(file, wage);
	getline(file, rounds);
	getline(file, spots);
	regex rx_wage("0*[1-9]\\d*\\.?\\d*|0+\\.[1-9]\\d*");
	regex rx_rounds("0*[1-9]\\d*");
	regex rx_spots("0*(\\d+\\s+)+0*\\d+\\s*");
	if (!regex_match(wage, rx_wage))
		return false;
	if (!regex_match(rounds, rx_rounds))
		return false;
	if (!regex_match(spots, rx_spots))
		return false;

	return spots_validate(spots);
}

int file_to_kenobet(char *arg, KenoBet& kb)
{
	fstream file;
	file.open(arg);
	if (!file) {
		return -1;
	}

	wage_t wage;
	int rounds;
	spot_t spot;
	file >> ws >> wage >> ws >> rounds;

	set_of_spot_t set {};
	kb.reset();
	while (file >> ws >> spot)
		kb.add_spot(spot);
	kb.set_wage(wage);
	file.close();
	return rounds;
}
