#include "WrongCat.hpp"

/*-------------------- CONSTRUCTEURS ET DESTRUCTEUR --------------------*/

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructeur called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &objectToCopy) : WrongAnimal() {
	std::cout << "Copy of WrongCat is created." << std::endl;
	*this = objectToCopy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed." << std::endl;
}

/*------------------------ FONCTIONS MEMBRES ------------------------*/

void WrongCat::makeSound() const {
	std::cout << "WrongCat makes : 😼 MEOOOOOOOOOOWWWWWW 😼" << std::endl;
}

/*---------------------- OPERATEURS DE SURCHAGE ----------------------*/

WrongCat &WrongCat::operator=(WrongCat const &objectB) {
	this->type = objectB.type;
	return (*this);
}