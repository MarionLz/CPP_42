#include "Fixed.hpp"

int main( void ) {
	std::cout << "Subject tests:" << std::endl;

	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << "My tests:" << std::endl;

	Fixed c(a + b);
	std::cout << "c = " << c << std::endl;
	if (c > b)
		std::cout << "c is bigger than b" << std::endl;
	else
		std::cout << "error" << std::endl;

	//std::cout << "c pre decrementation = " << --c << std::endl;

	Fixed d = c - a;
	std::cout << "b = " << d << std::endl;
	std::cout << "d = " << d << std::endl;
	if (d == b)
		std::cout << "d is equal to b" << std::endl;
	else
		std::cout << "d is not equal to b" << std::endl;

	Fixed e(b / Fixed(2));
	std::cout << "e = " << e << std::endl;

	return (0);
}