#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal *animal = new Dog();
	Animal *animal2 = new Cat();

	animal->makeSound();
	animal2->makeSound();
	
	delete animal;
	delete animal2;
	return (0);
}
