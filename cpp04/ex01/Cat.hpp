#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *CatBrain;
	public:
		Cat(void);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		void makeSound(void) const;
		~Cat(void);
};