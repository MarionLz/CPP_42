#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:

	int _rawBits;
	static const int _nbBits = 8;

	public:

	Fixed(void);
	Fixed(Fixed const & instanceToCopy);
	~Fixed(void);

	Fixed &operator=(Fixed const & instance);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif