//
// Created by fatih soymaz on 28.10.2023.
//

#ifndef CPPMODULE_WEAPON_HPP
#define CPPMODULE_WEAPON_HPP

#include "iostream"

class Weapon {
	private:
		std::string type;
	public:
	Weapon(std::string str);
	const std::string &getType();
	void setType(std::string type);
};


#endif //CPPMODULE_WEAPON_HPP
