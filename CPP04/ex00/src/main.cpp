#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;

i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete(meta);
delete(i);
delete(j);

std::cout << std::endl;

const WrongAnimal* atem = new WrongAnimal();
const WrongAnimal* k = new WrongCat();

std::cout << atem->getType() << " " << std::endl;
std::cout << k->getType() << " " << std::endl;

atem->makeSound();
k->makeSound();

delete(atem);
delete(k);

return 0;
}
