#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>

class ClapTrap {

	private :

	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

	public :

	ClapTrap(void);
	ClapTrap(ClapTrap const &objectToCopy);
	ClapTrap(std::string targetName);
	~ClapTrap();

	void setAttackDamage(int nbDamages);
	int getAttackDamage(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap & operator=(ClapTrap const &objectB);
};

#endif