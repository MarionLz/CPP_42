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
	Fixed(Fixed const & objectToCopy);
	Fixed(int const nbInteger);
	Fixed(float const nbFloat);
	~Fixed(void);

	Fixed &operator=(Fixed const &objectB);
	Fixed operator+(Fixed const &objectB);
	Fixed operator-(Fixed const &objectB);
	Fixed operator*(Fixed const &objectB);
	Fixed operator/(Fixed const &objectB);

	bool operator>(Fixed const &objectB);
	bool operator<(Fixed const &objectB);
	bool operator>=(Fixed const &objectB);
	bool operator<=(Fixed const &objectB);
	bool operator==(Fixed const &objectB);
	bool operator!=(Fixed const &objectB);

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &objectA, Fixed &objectB);
	static const Fixed &min(Fixed const &objectA, Fixed const &objectB);
	static Fixed &max(Fixed &objectA, Fixed &objectB);
	static const Fixed &max(Fixed const &objectA, Fixed const &objectB);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
	
};

std::ostream &operator<<(std::ostream& out, Fixed const & thisObject);

#endif