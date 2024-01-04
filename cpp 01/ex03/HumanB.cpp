#include "HumanB.hpp"


HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}


void	HumanB::Attack()
{
	if(weapon != NULL)
		std::cout << this->name << " attacks with their " << weapon->getType()<< std::endl;
	else
		std::cout << this->name << " throws his " << "fists." << std::endl;
}


void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

int c = 15;
int &a = c;