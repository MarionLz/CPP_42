#include "ClapTrap.hpp"
#include "colors.hpp"

/*-------------------- CONSTRUCTEURS ET DESTRUCTEUR --------------------*/

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructeur called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &objectToCopy) {
	*this = objectToCopy;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << GREEN << name << " is created." << RESET << std::endl;
	std::cout << "Score : " << GREEN << this->_name << RESET << ":" << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points." << std::endl;
	std::cout <<std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << GREEN << this->_name << RESET << " destroyed." << std::endl;
}

/*------------------------ FONCTIONS SET & GET -------------------------*/

void ClapTrap::setAttackDamage(int nbDamages) {
	this->_attackDamage = nbDamages;
}

int ClapTrap::getAttackDamage(void) {
	return (this->_attackDamage);
}

int ClapTrap::getHitPoint(void) {
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoint(void) {
	return (this->_energyPoints);
}

/*------------------------- FONCTIONS MEMBRES --------------------------*/

void ClapTrap::attack(const std::string& target) {

	if (this->_energyPoints > 0) {
		this->_energyPoints--;
		std::cout << "💥 Claptrap " << GREEN << this->_name << RESET << " attacks " << GREEN << target << RESET << ", causing " << this->_attackDamage << " points of damage ! 💥" << std::endl;
		std::cout << "Score : " << GREEN << this->_name << RESET << ":" << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points." << std::endl;
	}
	else {
		std::cout << "☠️ Claptrap " << GREEN << this->_name << RED << " can't attack because he's dead.☠️" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (this->_hitPoints > 0) {
		if (amount > (unsigned int)this->_hitPoints) {
			this->_hitPoints = 0;
		}
		else {
			this->_hitPoints -= amount;
		}
		std::cout << "😵 Claptrap " << GREEN << this->_name << RESET << " takes " << amount << " points of damage.😵" << std::endl;
		std::cout << "Score : " << GREEN << this->_name << RESET << ":" << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points." << std::endl;
	}
	else
		std::cout << "☠️  Claptrap " << GREEN << this->_name << RESET << " is already dead. ☠️" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (_energyPoints > 0) {
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "🩹 Claptrap " << GREEN << this->_name << RESET << " is repaired.🩹" << std::endl;
		std::cout << "Score : " << GREEN << this->_name << RESET << ":" << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points." << std::endl;
	}
	else {
		std::cout << "🥱 Claptrap " << GREEN << this->_name << RED << " has no energy point left to repair himself.🥱" << RESET << std::endl;
	}
}

bool ClapTrap::alive() {
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
		return (true);
	return (false);
}

/*---------------------- OPERATEURS DE SURCHAGE ----------------------*/

ClapTrap &ClapTrap::operator=(ClapTrap const &objectB) {
	this->_hitPoints = objectB._hitPoints;
	this->_energyPoints = objectB._energyPoints;
	this->_attackDamage = objectB._attackDamage;
	return (*this);
}
