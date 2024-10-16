#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = src.getType();
}

Dog &Dog::operator=(const Dog &src)
{
	this->type = src.getType();
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Hav Hav" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Default Dog destructor called" << std::endl;
}