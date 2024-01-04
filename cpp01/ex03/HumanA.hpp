#ifndef CPPMODULE_HUMANA_HPP
#define CPPMODULE_HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
	std::string name;
	Weapon &weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	
	void	Attack();
};


#endif //CPPMODULE_HUMANA_HPP
