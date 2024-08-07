#include "ClapTrap.hpp"

int main(void) {

	std::cout << "🐁🐈‍ Welcome in ClapTrap 🐁🐈" << std::endl << std::endl;

	std::cout << "⚔️  Let's the fight begin ! ⚔️" << std::endl << std::endl;


	ClapTrap tom("Tom");
	ClapTrap jerry("Jerry");

	std::cout << std::endl;

	tom.setAttackDamage(2);
	tom.attack("Jerry");
	jerry.takeDamage(tom.getAttackDamage());
	jerry.beRepaired(tom.getAttackDamage());

	std::cout << std::endl;

	jerry.setAttackDamage(10);
	jerry.attack("Tom");
	tom.takeDamage(jerry.getAttackDamage());
	jerry.attack("Tom");
	tom.takeDamage(jerry.getAttackDamage());
	tom.beRepaired(jerry.getAttackDamage());

	std::cout << std::endl;

	tom.setAttackDamage(4);
	jerry.setAttackDamage(6);
	for (int i = 0; i < 10; i++) {
		tom.attack("Jerry");
		jerry.takeDamage(tom.getAttackDamage());
		jerry.beRepaired(tom.getAttackDamage());
	}

	return (0);
}