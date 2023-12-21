#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	maxHp = 100;
	std::cout << "ScavTrap " +  name << " is created." << std::endl;
}

 ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	std::cout << "ScavTrap " << name << " is cloned." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	name = other.name + "_stCpy";
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	maxHp = other.maxHp;
	return *this;
}

void ScavTrap::guardGate()
{
	if (this->hitPoints <= 0)
		std::cout << name << "is already dead" << std::endl;
	else
		std::cout << "ScavTrap " << name << " is guard mode now." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target <<
		 " ,causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints -= 1;
	}
	else if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " needs to be repaired before trying to attack." << std::endl;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " doesn't have enough energy to attack." << std::endl;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is destroyed" << std::endl;
}
