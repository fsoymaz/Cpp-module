#ifndef CPP_03_CLAPTRAP_H
#define CPP_03_CLAPTRAP_H


#include <iostream>

class ClapTrap {
private:
    std::string name;
   unsigned int hitPoints;
   unsigned int energyPoints;
   unsigned int attackDamage;

public:
	ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;
};


#endif