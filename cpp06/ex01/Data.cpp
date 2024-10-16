#include "Data.hpp"

void	Data::setName(std::string	name)
{
	this->_name = name;
}

std::string		Data::getName(void) const
{
	return (this->_name);
}

void	Data::setAge(int	age)
{
	this->_age = age;
}

int		Data::getAge(void) const
{
	return (this->_age);
}
