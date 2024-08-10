#include "ScavTrap.hpp"
#include "colors.hpp"

/*-------------------- CONSTRUCTEURS ET DESTRUCTEUR --------------------*/

ScavTrap::ScavTrap() {
	std::cout << "Scavtrap default constructeur called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &objectToCopy) : ClapTrap() {
	std::cout << "Copy of Scavtrap " << GREEN << objectToCopy._name << " is created." << RESET << std::endl;
	*this = objectToCopy;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Scavtrap " << GREEN << name << " is created." << RESET << std::endl;
	std::cout << "Score : " << GREEN << this->_name << RESET << ":" << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points." << std::endl;
	std::cout <<std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scavtrap " << GREEN << this->_name << RESET << " destroyed." << std::endl;
}

/*------------------------- FONCTIONS MEMBRES --------------------------*/

void ScavTrap::attack(const std::string& target) {

	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_energyPoints--;
		std::cout << "💥 ScavTrap " << GREEN << this->_name << RESET << " attacks " << GREEN << target << RESET << ", causing " << this->_attackDamage << " points of damage ! 💥" << std::endl;
		std::cout << "Score : " << GREEN << this->_name << RESET << ":" << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points." << std::endl;
	}
	else {
		std::cout << "☠️ ScavTrap " << GREEN << this->_name << RED << " can't attack because he's dead.☠️" << RESET << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << " ScavTrap is now in Gate keeper mode" << std::endl;
}

/*---------------------- OPERATEURS DE SURCHAGE ----------------------*/

ScavTrap &ScavTrap::operator=(ScavTrap const &objectB) {
	this->_hitPoints = objectB._hitPoints;
	this->_energyPoints = objectB._energyPoints;
	this->_attackDamage = objectB._attackDamage;
	return (*this);
}