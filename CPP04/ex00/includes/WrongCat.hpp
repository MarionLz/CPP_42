#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat : public WrongAnimal {

	public :

	WrongCat();
	WrongCat(WrongCat const &objectToCopy);
	~WrongCat();

	void makeSound() const;

	WrongCat & operator=(WrongCat const &objectB);

};

#endif