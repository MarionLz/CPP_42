#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>
# include <iostream>

class Cat : public Animal {

	public :

	Cat();
	Cat(Cat const &objectToCopy);
	~Cat();

	void makeSound() const;

	Cat & operator=(Cat const &objectB);

};

#endif