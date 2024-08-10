#include "Animal.hpp"

/*-------------------- CONSTRUCTEURS ET DESTRUCTEUR --------------------*/

Animal::Animal() {
	std::cout << "Animal default constructeur called" << std::endl;
	this->type = "Undefine animal";
}

Animal::Animal(Animal const &objectToCopy) {
	std::cout << "Copy of Animal is created." << std::endl;
	*this = objectToCopy;
}

Animal::~Animal() {
	std::cout << "Animal destroyed." << std::endl;
}

/*-------------------- FONCTIONS GET & SET --------------------*/

void Animal::makeSound() const {
	std::cout << "BKSFLDCNAAAOCJN (undefine sound for an undefine animal)" << std::endl;
}

std::string Animal::getType(void) const {
	return (this->type);
}

/*---------------------- OPERATEURS DE SURCHAGE ----------------------*/

/*Animal &Animal::operator=(Animal const &objectB) {
	return (*this);
}*/