#include "Fixed.hpp"

/*--------------------CONSTRUCTEURS--------------------*/

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(Fixed const & objectToCopy) {
	*this = objectToCopy;
}

// convertit l'entier passe en parametre en nb a virgule fixe
// << _nbBits eauivaut a faire * 256
Fixed::Fixed(int const nbInteger) {
	this->_rawBits = nbInteger << _nbBits;
}

// convertit le float passe en parametre en nb a virgule fixe
Fixed::Fixed(float const nbFloat) {
	this->_rawBits = roundf(nbFloat * (1 << _nbBits));
}

/*---------------------DESTRUCTEUR---------------------*/

Fixed::~Fixed() {}

/*--------------OPERATEURS D'ARITHMETIQUE--------------*/

Fixed &Fixed::operator=(Fixed const &objectB) {
	this->setRawBits(objectB.toFloat());
	return (*this);
}

Fixed Fixed::operator+(Fixed const &objectB) {
	return (Fixed(this->toFloat() + objectB.toFloat()));
}

Fixed Fixed::operator-(Fixed const &objectB) {
	return (Fixed(this->toFloat() + objectB.toFloat()));
}

Fixed Fixed::operator*(Fixed const &objectB) {
	return (Fixed(this->toFloat() * objectB.toFloat()));
}

Fixed Fixed::operator/(Fixed const &objectB) {
	return (Fixed(this->toFloat() / objectB.toFloat()));
}

/*--------------OPERATEURS DE COMPARAISON--------------*/

bool Fixed::operator>(Fixed const &objectB) {
	if (this->_rawBits > objectB.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const &objectB) {
	if (this->_rawBits < objectB.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &objectB) {
	if (this->_rawBits >= objectB.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &objectB) {
	if (this->_rawBits <= objectB.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &objectB) {
	if (this->_rawBits == objectB.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &objectB) {
	if (this->_rawBits != objectB.getRawBits())
		return (true);
	return (false);
}

/*-------------OPERATEURS D'INCREMENTATION-------------*/

Fixed &Fixed::operator++() {
	this->_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_rawBits++;
	return (temp);
}

Fixed &Fixed::operator--() {
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_rawBits--;
	return (temp);
}

/*----------------------MIN & MAX----------------------*/

Fixed &Fixed::min(Fixed &objectA, Fixed &objectB) {
	if (objectA.getRawBits() < objectB.getRawBits())
		return (objectA);
	return (objectB);
}

Fixed const &Fixed::min(Fixed const &objectA, Fixed const &objectB) {
	if (objectA.getRawBits() < objectB.getRawBits())
		return (objectA);
	return (objectB);
}

Fixed &Fixed::max(Fixed &objectA, Fixed &objectB) {
	if (objectA.getRawBits() > objectB.getRawBits())
		return (objectA);
	return (objectB);
}

Fixed const &Fixed::max(Fixed const &objectA, Fixed const &objectB) {
	if (objectA.getRawBits() > objectB.getRawBits())
		return (objectA);
	return (objectB);
}

/*----------------------GET & SET----------------------*/

int Fixed::getRawBits(void) const {
	return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

/*---------------------CONVERSION----------------------*/

float Fixed::toFloat(void) const {
	return (static_cast<float>(_rawBits) / (1 << _nbBits));
}

int Fixed::toInt(void) const {
	return (static_cast<int>(_rawBits) / (1 << _nbBits));
}

/*----------------OPERATEUR D'INSERTION----------------*/

std::ostream& operator<<(std::ostream& out, Fixed const & thisObjects)
{
	out << thisObjects.toFloat();
	return (out);
}