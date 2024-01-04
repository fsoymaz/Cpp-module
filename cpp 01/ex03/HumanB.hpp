#ifndef CPPMODULE_HUMANB_HPP
#define CPPMODULE_HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string);
		void Attack();
		void setWeapon(Weapon &weapon);
};
#endif
