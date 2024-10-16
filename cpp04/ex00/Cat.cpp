#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = src.getType();
}

Cat &Cat::operator=(const Cat &src)
{
	this->type = src.getType();
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Default Cat destructor called" << std::endl;
}