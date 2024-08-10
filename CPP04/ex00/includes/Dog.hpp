#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

class Dog : public Animal {
	
	public :

	Dog();
	Dog(Dog const &objectToCopy);
	~Dog();

	void makeSound() const;

	Dog & operator=(Dog const &objectB);

};

#endif