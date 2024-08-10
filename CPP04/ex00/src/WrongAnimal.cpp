#include "WrongAnimal.hpp"

/*-------------------- CONSTRUCTEURS ET DESTRUCTEUR --------------------*/

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructeur called" << std::endl;
	this->type = "Undefine WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &objectToCopy) {
	std::cout << "Copy of WrongAnimal is created." << std::endl;
	*this = objectToCopy;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destroyed." << std::endl;
}

/*-------------------- FONCTIONS GET & SET --------------------*/

void WrongAnimal::makeSound() const {
	std::cout << "BKSFLDCNAAAOCJN (undefine sound for an undefine WrongAnimal)" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (this->type);
}

/*---------------------- OPERATEURS DE SURCHAGE ----------------------*/

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &objectB) {
	this->type = objectB.type;
	return (*this);
}