#pragma once

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &src);
	std::string getType(void) const;
	void makeSound(void) const;
	~WrongAnimal(void);
};