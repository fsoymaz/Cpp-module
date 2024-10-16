#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		std::string getType(void) const;
		virtual void makeSound(void) const;
		virtual ~Animal(void);
};