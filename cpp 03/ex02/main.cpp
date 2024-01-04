#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap clapTrap("CL4P-TP");
	clapTrap.takeDamage(20);
	clapTrap.beRepaired(10);

	ScavTrap scavTrap("SCV-TP");
	scavTrap.takeDamage(30);
	scavTrap.beRepaired(15);
	scavTrap.guardGate();

	FragTrap fragTrap("FR4G-TP");
	fragTrap.takeDamage(40);
	fragTrap.beRepaired(20);
	fragTrap.highFivesGuys();

	return (0);
}