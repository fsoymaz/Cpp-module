#include "Phonebook.hpp"

int	ft_isdigit(std::string phone)
{
	for (int i = 0; phone[i]; i++)
	{
		if (phone[i] < '0' || phone[i] > '9')
			return  (0);
	}
	return  (1);
}

std::string takeArgument(std::string str, std::string str2)
{
	do {
		std::cout << str;
		std::getline(std::cin, str2);
	}
	while (str2.empty());
	return (str2);
}

void Phonebook::Add(std::string name, std::string last, std::string darkest, std::string phone, std::string nickName)
{
	this->contact[this->i % 8].setFirstName(takeArgument("First Name: ", name));
	this->contact[this->i % 8].setLastName(takeArgument("Last Name: ", last));
	this->contact[this->i % 8].setNickName(	takeArgument("Nick Name: ", nickName));
	while (!ft_isdigit(phone) || phone.empty())
    {
        phone.clear();
        std::cout << "Phone Number: ";
        std::getline(std::cin, phone);
    }
	this->contact[this->i % 8].setPhoneNumber(phone);
	this->contact[this->i % 8].setDarkSecret(	takeArgument("Darkest Secret: ", darkest));
	i++;
};

int Phonebook::getI()  {
	return i;
}

void Phonebook::setI(int i) {
	this->i = i;
}

Contact* Phonebook::getContact()
{
	return contact;
}