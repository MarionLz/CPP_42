#include "FragTrap.hpp"
#include "colors.hpp"

/*-------------------- CONSTRUCTEURS ET DESTRUCTEUR --------------------*/

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructeur called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &objectToCopy) : ClapTrap() {
	std::cout << "Copy of FragTrap " << GREEN << objectToCopy._name << " is created." << RESET << std::endl;
	*this = objectToCopy;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << GREEN << name << " is created." << RESET << std::endl;
	std::cout << "Score : " << GREEN << this->_name << RESET << ":" << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points." << std::endl;
	std::cout <<std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << GREEN << this->_name << RESET << " destroyed." << std::endl;
}

/*------------------------- FONCTIONS MEMBRES --------------------------*/

void FragTrap::highFivesGuys() {
	std::cout << "🙏  FragTrap " << GREEN << this->_name << RESET << " says : 'HIGH FIVE GUYS !' 🙏" << std::endl;
}

/*---------------------- OPERATEURS DE SURCHAGE ----------------------*/

FragTrap &FragTrap::operator=(FragTrap const &objectB) {
	this->_hitPoints = objectB._hitPoints;
	this->_energyPoints = objectB._energyPoints;
	this->_attackDamage = objectB._attackDamage;
	return (*this);
}