#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {

	protected :

	std::string type;

	public :

	WrongAnimal();
	WrongAnimal(WrongAnimal const &objectToCopy);
	virtual ~WrongAnimal();

	virtual void makeSound() const;
	std::string getType(void) const;

	WrongAnimal & operator=(WrongAnimal const &objectB);

};

#endif