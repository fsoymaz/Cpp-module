#include "Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(5, "ARMUT");
	for (int i = 0; i < 5; ++i) {
		zombie->announce();
	}
	delete[] zombie;
}