#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
	this->DogBrain = new Brain();
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->DogBrain = new Brain();
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	this->type = src.getType();
	delete this->DogBrain;
	this->DogBrain = new Brain(*src.DogBrain);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Hav hav" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Default Dog destructor called" << std::endl;
	delete this->DogBrain;
}