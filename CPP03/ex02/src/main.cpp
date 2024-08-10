#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

	std::cout << "🐁🐈‍ Welcome in ClapTrap 🐁🐈" << std::endl << std::endl;

	std::cout << "⚔️  Let's the fight begin ! ⚔️" << std::endl << std::endl;

	ScavTrap robot("Robot");
	FragTrap superman("Superman");

	superman.attack("Robot");
	robot.takeDamage(superman.getAttackDamage());
	robot.beRepaired(superman.getAttackDamage());

	std::cout << std::endl;

	robot.setAttackDamage(15);
	for (int i = 0; i < 6; i++) {
		if (superman.alive())
			robot.attack("Superman");
		if (robot.alive()) {
			superman.takeDamage(robot.getAttackDamage());
			superman.beRepaired(robot.getAttackDamage());
		}
		if (robot.alive()) {
			superman.highFivesGuys();
			superman.attack("Robot");
		}
		if (superman.alive()) {
			robot.takeDamage(superman.getAttackDamage());
			robot.beRepaired(superman.getAttackDamage());	
		}	
	}

	return (0);
}