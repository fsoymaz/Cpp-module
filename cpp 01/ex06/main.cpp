#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl harl;
		harl.complain(av[1]);
	}
	else
		std::cout << "Insufficent/Wrong Arguments. Please follow the template : ./harl DEBUG or INFO or WARNING or ERROR" << std::endl;
	return (0);
}