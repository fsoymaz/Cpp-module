
#include "Phonebook.hpp"

void	addFunction(Phonebook *phn)
{
	std::string name;
	std::string lastName;
	std::string nickName;
	std::string phone;
	std::string darkest;
	(*phn).Add(name, lastName, phone, darkest, nickName);
}

void	write(Phonebook *phn, int index)
{
	std::cout << "|" << std::setw(10) << index % 8 << "|";
	if ((*phn).getContact()[index % 8].getFirstName().length() > 9)
		std::cout << std::setw(10) << (*phn).getContact()[index
			% 8].getFirstName().substr(0, 9) + "."
					<< "|";
	else
		std::cout << std::setw(10) << (*phn).getContact()[index
			% 8].getFirstName() << "|";
	if ((*phn).getContact()[index % 8].getLastName().length() > 9)
		std::cout << std::setw(10) << (*phn).getContact()[index
			% 8].getLastName().substr(0, 9) + "."
					<< "|";
	else
		std::cout << std::setw(10) << (*phn).getContact()[index
			% 8].getLastName() << "|";
	if ((*phn).getContact()[index % 8].getNickName().length() > 9)
		std::cout << std::setw(10) << (*phn).getContact()[index
			% 8].getNickName().substr(0, 9) + "."
					<< "|";
	else
		std::cout << std::setw(10) << (*phn).getContact()[index
			% 8].getNickName() << "|";
	std::cout << "\n";
}

void	searchFunction(Phonebook *phn)
{
	unsigned int	index;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|   index  |   name   |  surname | nickname |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int j = 0; (j < phn->getI() && j < 8); j++)
	{
		write(phn, j);
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	while (true)
	{
		std::cout << "please enter an index : ";
		if (std::cin >> index)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (index >= 0 && index < phn->getI())
			{
				write(phn, index);
				break ;
			}
			else
				std::cout << "Invalid index. Please enter a valid index." << std::endl;
		}
		else
		{
			std::cout << "Invalid input. Please enter a valid index." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

int	main(void)
{
	std::cout << "WELCOME" << std::endl;
	std::cout << "Type ADD to add a new person to the contact list." << std::endl;
	std::cout << "Please type SEARCH to see the people you added to your contact list." << std::endl;

	std::string str;
	Phonebook phn;

	while (str.compare("EXIT") != 0)
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (str.compare("ADD") == 0)
			addFunction(&phn);
		else if (str.compare("SEARCH") == 0)
			searchFunction(&phn);
	}

	return (0);
}