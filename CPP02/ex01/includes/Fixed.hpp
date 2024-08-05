#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:

	int _rawBits;
	static const int _nbBits = 8;

	public:

	Fixed(void);
	Fixed(Fixed const & instanceToCopy);
	Fixed(int const nbInteger);
	Fixed(float const nbFloat);
	~Fixed(void);

	Fixed &operator=(Fixed const & instance);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	
};

std::ostream &operator<<(std::ostream& out, Fixed const & this_instance);

#endif