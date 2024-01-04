#include "ScavTrap.hpp"

int main(void){
	ScavTrap s("mkati");
	s.attack("ruzgar");
	s.beRepaired(1);
	s.takeDamage(15);
	s.guardGate();
	return (0);
}