#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *DogBrain;
	public:
		Dog(void);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		void makeSound(void) const;
		~Dog(void);
};