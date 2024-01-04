#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {
	this->name = name;
}

void	HumanA::Attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
