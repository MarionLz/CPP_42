#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

	std::cout << "🐁🐈‍ Welcome in ClapTrap 🐁🐈" << std::endl << std::endl;

	std::cout << "⚔️  Let's the fight begin ! ⚔️" << std::endl << std::endl;

	ScavTrap robot("Robot");
	ClapTrap superman("Superman");

	superman.setAttackDamage(5);
	superman.attack("Robot");
	robot.takeDamage(superman.getAttackDamage());
	robot.beRepaired(superman.getAttackDamage());

	std::cout << std::endl;

	robot.setAttackDamage(2);
	for (int i = 0; i < 6; i++) {
		if (superman.alive()) {
			robot.attack("Superman");
			robot.guardGate();
		}
		if (robot.alive()) {
			superman.takeDamage(robot.getAttackDamage());
			superman.beRepaired(robot.getAttackDamage());
		}
		if (robot.alive())
			superman.attack("Robot");
		if (superman.alive())
			robot.takeDamage(superman.getAttackDamage());
	}
	/*ClapTrap tom("Tom");
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
	}*/

	return (0);
}