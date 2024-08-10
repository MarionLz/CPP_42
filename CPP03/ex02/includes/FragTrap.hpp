#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public :

	FragTrap();
	FragTrap(FragTrap const &objectToCopy);
	FragTrap(std::string name);
	~FragTrap();

	void highFivesGuys(void);

	FragTrap & operator=(FragTrap const &objectB);

};

#endif