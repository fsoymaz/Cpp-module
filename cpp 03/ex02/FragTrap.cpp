#include "FragTrap.hpp"

FragTrap::FragTrap(){}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	maxHp = 100;
	std::cout << "FragTrap " +  name << " is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
	std::cout << "FragTrap" << name << "is cloned" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	name = copy.name + "_stCpy";
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
	maxHp = copy.maxHp;
	return *this;
}


void FragTrap::highFivesGuys(void)
{
	if (this->hitPoints <= 0)
		std::cout << name << "is already dead" << std::endl;
	else
		std::cout << name << " gives out the highest of the fives!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destroyed" << std::endl;
}
