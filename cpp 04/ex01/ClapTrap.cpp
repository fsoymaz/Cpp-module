#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10),
	energyPoints(10), attackDamage(0), maxHp(10)
{
	std::cout << "ClapTrap " << name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << name << " is cloned." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	name = other.name + "_copy";
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	maxHp = other.maxHp;
	return (*this);
}

// Attack function implementation
void ClapTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ",	causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints -= 1;
	}
	else if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " needs to be repaired before trying to attack." << std::endl;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have enough energy to attack." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
	}
	else
	{
		if (amount >= hitPoints)
		{
			hitPoints = 0;
			std::cout << "ClapTrap " << name << " died with this blow." << std::endl;
		}
		else
		{
			hitPoints -= amount;
			std::cout << "ClapTrap " << name << " damaged " << amount << " points." << std::endl;
		}
	}
}

// Be repaired function implementation
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == maxHp)
	{
		std::cout << "ClapTrap " << name << " does not need to renew himself" << std::endl;
		return ;
	}
	if (energyPoints > 0 && hitPoints < maxHp && hitPoints > 0)
	{
		energyPoints -= 1;
		if (amount + hitPoints >= maxHp)
		{
			hitPoints = maxHp;
			std::cout << "ClapTrap " << name << " is renewed!" << std::endl;
		}
		else
		{
			hitPoints += amount;
			std::cout << "ClapTrap " << name << " renewed itself " << amount << " points and ClapTrap " << name << "'s new hitPoints = " << hitPoints << std::endl;
		}
	}
	else if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already dead." << std::endl;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << "'s doesn't have energy" << std::endl;
	}
}

std::string ClapTrap::getName() const
{
	return (name);
}

int ClapTrap::getHitPoints() const
{
	return (hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (attackDamage);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is destroyed." << std::endl;
}