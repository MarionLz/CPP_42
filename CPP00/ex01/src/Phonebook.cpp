#include "Phonebook.hpp"

const int Phonebook::_MAX_CONTACT = 8;

void Phonebook::addContact(int index, Contact new_contact) {
	this->_contacts[index] = new_contact;
}

void Phonebook::printContactField(std::string field) {
	size_t size = field.size();

	if (field.empty()) {
		std::cout << "          ";
	}
	else if (size > 10) {
		field.resize(10);
		field[9] = '.';
	}
	else if (size < 10) {
		for (size_t i = 0; i < 10 - size; i++)
			std::cout << " ";
	}
	std::cout << field << "|";
}

void Phonebook::displayContact(int index) const {
	std::cout << CYAN << "----------Contact Details----------" << std::endl;
	std::cout << "First name : " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last name : " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname : " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone number : " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << this->_contacts[index].getDarkestSecret() << std::endl;
	std::cout << "-----------------------------------" << WHITE << std::endl;
}

void Phonebook::displayPhonebook(int nb_contact) {
	int	i = 0;
	int searched_index;
	std::string input;

	std::cout << BLUE << "------------ Registered Contacts ------------" << std::endl << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << WHITE << std::endl;
	while (i < _MAX_CONTACT) {
		std::cout << BLUE << "|         " << i << "|";
		printContactField(this->_contacts[i].getFirstName());
		printContactField(this->_contacts[i].getLastName());
		printContactField(this->_contacts[i].getNickname());
		std::cout << WHITE << std::endl;
		i++;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (nb_contact == 0) {
		std::cout << std::endl << RED << "No contact has been added to the phonebook yet." << WHITE << std::endl;
	}
	else {
		do {
		std::cout << std::endl << "Which contact do you want to display ?" << std::endl;
		std::getline(std::cin, input);
		std::istringstream iss(input);
		if (!is_digits(input) || !(iss >> searched_index))
			std::cout << RED << "⛔ Invalid index ⛔"<< WHITE << std::endl;
		else if (searched_index >= nb_contact) {
			std::cout << RED << "⛔ This contact doesn't exist. ⛔"<< WHITE << std::endl;
		}
		} while (searched_index >= nb_contact);
		this->displayContact(searched_index);
	}
}

Phonebook::Phonebook(void) {
}

Phonebook::~Phonebook(void) {}