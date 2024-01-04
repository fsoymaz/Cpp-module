#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.Attack();
		club.setType("some other type of club");
		bob.Attack();
	}
	{
		Weapon club = Weapon("weapon");
		HumanB jim("Jim");
		//jim.Attack();
		jim.setWeapon(club);
		jim.Attack();
		club.setType("knife");
		jim.Attack();
	}
	return 0;
}
