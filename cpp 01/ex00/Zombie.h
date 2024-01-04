//
// Created by fatih soymaz on 28.10.2023.
//

#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

#include "iostream"

class Zombie {
	private:
		std::string name;
	public:
		Zombie(std::string name);
		void	announce(void);
		~Zombie();
};

void	randomChump(std::string name);
Zombie 	*newZombie(std::string name);

#endif //CPP01_ZOMBIE_H
