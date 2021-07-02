#ifndef KENOBET_H
#define KENOBET_H
#include <vector>
#include <algorithm>

using spot_t = unsigned short int;
using wage_t = float;
using set_of_spot_t = std::vector<spot_t>;
using set_of_spot_it = std::vector<spot_t>::iterator;

class KenoBet {
public:
        KenoBet(std::initializer_list<spot_t> l, wage_t n) : wage{n}, spots(l) {};
        KenoBet(set_of_spot_it b, set_of_spot_it e, wage_t n) : wage{n}, spots(b, e) {};
        KenoBet() : wage{0}, spots{} {};
        ~KenoBet() {};

	/* @brief Gets value of wage.
	 * @return Value of wage.
	 */
        wage_t get_wage(void) const { return wage; }

	/* @brief Gets a copy of spots set.
	 * @return A copy of spots set.
	 */
        set_of_spot_t get_spots(void) const { return spots; }

	/* @brief Get size of spots set.
	 * @return Size of spots set.
	 */
        size_t get_spots_size(void) const { return spots.size(); }

	/* @brief Zeroes the wage and empties the spots set.
	 */
        void reset(void) { wage = 0; spots.clear(); };

	/* @brief Sets a new value for wage.
	 * @param w New wage value.
	 * @return True is new wage is above 0; false if not.
	 */
        bool set_wage(wage_t w)
	{
		wage = w;
		return (w > 0) ? true : false;
	}

	/* @brief Adds a new spot to spots set, unless already in it.
	 * @param s New spot value.
	 * @return True is spot is added succesfully; false if not.
	 */
        bool add_spot(spot_t s)
	{
		if (std::any_of(spots.begin(), spots.end(),
		   [s](spot_t i){ return i==s; }))
			return false;
		spots.push_back(s);
		return true;
	}

	/* @brief Gets hits based on a list of numbers, assuming there
	 * aren't any duplicated values inside spots set of said list.
	 * @param nums List of numbers.
	 * @return A set of all hits.
	 */
        set_of_spot_t get_hits(const set_of_spot_t& nums) const
	{
		set_of_spot_t hits {};
		for (auto& s : spots) {
			for (auto& n : nums) {
				if (s == n)
					hits.push_back(n);
			}
		}
		return hits;
	}

private:
        wage_t wage;
        set_of_spot_t spots;
};
#endif

