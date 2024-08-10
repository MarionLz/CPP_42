#include "Dog.hpp"

/*-------------------- CONSTRUCTEURS ET DESTRUCTEUR --------------------*/

Dog::Dog() {
	std::cout << "Dog default constructeur called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &objectToCopy) : Animal() {
	std::cout << "Copy of Dog is created." << std::endl;
	*this = objectToCopy;
}

Dog::~Dog() {
	std::cout << "Dog destroyed." << std::endl;
}

/*------------------------ FONCTIONS MEMBRES ------------------------*/

void Dog::makeSound() const {
	std::cout << "Dog makes : 🐶 WOUF WOUF WOUF 🐶" << std::endl;
}

/*---------------------- OPERATEURS DE SURCHAGE ----------------------*/

Dog &Dog::operator=(Dog const &objectB) {
	this->type = objectB.type;
	return (*this);
}