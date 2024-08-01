#include "Contact.hpp"

void Contact::setFirstName(std::string input) {
	this->_first_name = input;
}

std::string Contact::getFirstName(void) const {
	return this->_first_name;
}

void Contact::setLastName(std::string input) {
	this->_last_name = input;
}

std::string Contact::getLastName(void) const {
	return this->_last_name;
}

void Contact::setNickname(std::string input) {
	this->_nickname = input;
}

std::string Contact::getNickname(void) const {
	return this->_nickname;
}

void Contact::setPhoneNumber(std::string input) {
	this->_phone_number = input;
}

std::string Contact::getPhoneNumber(void) const {
	return this->_phone_number;
}

void Contact::setDarkestSecret(std::string input) {
	this->_darkest_secret = input;
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkest_secret;
}

Contact::Contact(void) {}

Contact::~Contact(void) {}