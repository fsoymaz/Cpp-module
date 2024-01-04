//
// Created by fatih soymaz on 28.10.2023.
//

#include "Zombie.hpp"

void    Zombie::setName(std::string name)
{
	this->name = name;
}
void	Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;

}