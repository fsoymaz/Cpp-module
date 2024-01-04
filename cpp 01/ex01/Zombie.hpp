//
// Created by fatih soymaz on 28.10.2023.
//

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "iostream"

class Zombie {
private:
	std::string name;
public:
	void    setName(std::string name);
	void	announce(void);
	~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif
