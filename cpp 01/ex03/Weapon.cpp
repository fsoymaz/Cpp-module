//
// Created by fatih soymaz on 28.10.2023.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	this->type = str;
}

const std::string &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}
