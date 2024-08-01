#include "Contact.hpp"
#include "Phonebook.hpp"
#include "main.hpp"
#include <iostream>
#include <stdlib.h>
#include <limits>

void print_welcome_msg(void) {
	std::cout << "☎️  Welcome to this 1980 vintage Phonebook ☎️" << std::endl;
}

void print_cmd_list(void) {
	std::cout << "Please enter one of the following command : ADD, SEARCH or EXIT." << std::endl;
}

bool valid_command(std::string command) {
	if (command == "ADD" || command == "SEARCH" || command == "EXIT") {
		return (true);
	}
	else {
		std::cout << RED << "⛔ Invalid command ⛔" << WHITE << std::endl;
		return (false);
	}
}

bool is_digits(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

std::string check_input(std::string instruction, int flag) {
	std::string input;

	while (input.empty()) {
		std::cout << instruction << std::endl;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cerr << RED << "⛔ Input can't be empty. ⛔" << WHITE << std::endl;
		}
		if (flag == 1) {
			if (!is_digits(input)) {
				std::cerr << RED << "⛔ Phone number can contain only digits. ⛔" << WHITE << std::endl;
				input = "";
			}
		}
	}
	return (input);
}

Contact setContactFields() {
	Contact new_contact;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	new_contact.setFirstName(check_input("Enter your first name :", 0));
	new_contact.setLastName(check_input("Enter your last name :", 0));
	new_contact.setNickname(check_input("Enter your nickname :", 0));
	new_contact.setPhoneNumber(check_input("Enter your phone number :", 1));
	new_contact.setDarkestSecret(check_input("What is your darkest secret :", 2));
	std::cout << GREEN << "☑️  New contact registered ☑️" << WHITE << std::endl;
	return (new_contact);
}

int	main(void) {
	Phonebook phonebook;
	std::string command = "";
	int index = 0;
	int nb_contact = 0;

	print_welcome_msg();
	while (1) {
		do {
			print_cmd_list();
			std::cin >> command;
		} while (valid_command(command) == false);
		if (command == "ADD") {
			phonebook.addContact(index, setContactFields());
			index++;
			if (index == 8)
				index = 0;
			if (nb_contact < 8)
				nb_contact++;
		}
		else if (command == "SEARCH") {
			phonebook.displayPhonebook(nb_contact);
		}
		else if (command == "EXIT") {
			std::cout << "👋 Thanks for using this awesome 1980 vintage Phonebook, bye ! 👋" << std::endl;
			std::exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
