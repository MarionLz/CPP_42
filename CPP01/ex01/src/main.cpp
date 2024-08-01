#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
	int i = 10;
	Zombie *horde = zombieHorde(i, "Tony");

	for (int j = 0; j < i; j++)
		horde[j].announce();
	
	delete[] horde;
}