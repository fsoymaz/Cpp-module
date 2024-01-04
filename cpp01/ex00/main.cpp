#include "Zombie.h"
int main(void)
{
	Zombie *zombie = newZombie("armut");
	zombie->announce();
	randomChump("elma");
	delete zombie;
}
