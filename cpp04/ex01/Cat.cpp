#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
	this->CatBrain = new Brain();
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->CatBrain = new Brain();
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	this->type = src.getType();
	delete this->CatBrain;
	this->CatBrain = new Brain(*src.CatBrain);
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Default Cat destructor called" << std::endl;
	delete this->CatBrain;
}