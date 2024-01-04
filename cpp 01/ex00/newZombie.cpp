//
// Created by fatih soymaz on 28.10.2023.
//

#include "Zombie.h"

Zombie	*newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return  zombie;
}