#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = src.getType();
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	this->type = src.getType();
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Weow" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Default WrongCat destructor called" << std::endl;
}