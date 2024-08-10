#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {

	protected :

	std::string type;

	public :

	Animal();
	Animal(Animal const &objectToCopy);
	virtual ~Animal();

	virtual void makeSound() const;
	std::string getType(void) const;

	Animal & operator=(Animal const &objectB);

};

#endif