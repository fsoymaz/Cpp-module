#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = "evil thoughts";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor Call" << std::endl;
}