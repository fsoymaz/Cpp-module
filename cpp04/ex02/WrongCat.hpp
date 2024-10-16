#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(std::string _type);
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &src);
	void makeSound(void) const;
	~WrongCat(void);
};