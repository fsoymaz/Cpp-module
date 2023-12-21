#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

class Phonebook
{
	private:
	int i;
	Contact contact[8];

	public:
	void Add(std::string, std::string, std::string, std::string, std::string);
	Contact *getContact();
	int getI();
	void setI(int i);

};

#endif