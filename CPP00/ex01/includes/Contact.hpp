#ifndef CONTACT_H
# define CONTACT_H

#include "main.hpp"
#include <string>

class Contact
{
	private:

	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	public:

	//get : donne un acces en lecteur sur l'attribut (pas de modification de l'attribut).
	//set : permet d'assigner une autre valeur à l'attribut.
	void setFirstName(std::string input);
	std::string getFirstName(void) const;

	void setLastName(std::string input);
	std::string getLastName(void) const;

	void setNickname(std::string input);
	std::string getNickname(void) const;

	void setPhoneNumber(std::string input);
	std::string getPhoneNumber(void) const;	

	void setDarkestSecret(std::string input);
	std::string getDarkestSecret(void) const;

	Contact(void);
	~Contact(void);
};

#endif