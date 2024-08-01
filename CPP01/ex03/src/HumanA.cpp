#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon_ref(weapon) {
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon_ref.getType() << std::endl;
}

HumanA::~HumanA() {}