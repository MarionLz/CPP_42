#include "Cat.hpp"

/*-------------------- CONSTRUCTEURS ET DESTRUCTEUR --------------------*/

Cat::Cat() {
	std::cout << "Cat default constructeur called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &objectToCopy) : Animal() {
	std::cout << "Copy of Cat is created." << std::endl;
	*this = objectToCopy;
}

Cat::~Cat() {
	std::cout << "Cat destroyed." << std::endl;
}

/*------------------------ FONCTIONS MEMBRES ------------------------*/

void Cat::makeSound() const {
	std::cout << "Cat makes : 😼 MEOOOOOOOOOOWWWWWW 😼" << std::endl;
}

/*---------------------- OPERATEURS DE SURCHAGE ----------------------*/

Cat &Cat::operator=(Cat const &objectB) {
	this->type = objectB.type;
	return (*this);
}