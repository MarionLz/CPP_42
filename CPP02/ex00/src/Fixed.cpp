#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & instanceToCopy) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(instanceToCopy.getRawBits());
}

Fixed &Fixed::operator=(Fixed const & instance) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = instance.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}