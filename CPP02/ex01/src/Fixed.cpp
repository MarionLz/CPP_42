#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & instanceToCopy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = instanceToCopy;
}

// convertit un entier en nb a virgule fixe
// << _nbBits eauivaut a faire * 256
Fixed::Fixed(int const nbInteger) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = nbInteger << _nbBits;
}

Fixed::Fixed(float const nbFloat) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(nbFloat * (1 << _nbBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const & instance) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(instance.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(_rawBits) / (1 << _nbBits));
}

int Fixed::toInt(void) const {
	return (static_cast<int>(_rawBits) / (1 << _nbBits));
}

std::ostream& operator<<(std::ostream& out, Fixed const & this_instance)
{
	out << this_instance.toFloat();
	return (out);
}