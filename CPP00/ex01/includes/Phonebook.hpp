#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include "main.hpp"
#include <iostream>
#include <sstream>
#include <limits>

class Phonebook
{
	private:

	Contact _contacts[8];
	static int const _MAX_CONTACT;

	public:

	Phonebook(void);
	~Phonebook(void);
	void addContact(int index, Contact new_contact);
	void displayPhonebook(int index);
	void displayContact(int index) const;
	void printContactField(std::string field);
};

#endif