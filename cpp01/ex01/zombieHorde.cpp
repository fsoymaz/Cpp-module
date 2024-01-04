//
// Created by fatih soymaz on 28.10.2023.
//

#include "Zombie.hpp"



Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *zombieAry = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombieAry[i].setName(name);
	}
	return zombieAry;
}