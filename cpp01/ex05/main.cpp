#include "Harl.hpp"

int main()
{
    Harl harl;
	std::string input;
	std::cout << "Please choose one: \n1. DEBUG \n2. INFO \n3. WARNING \n4. ERROR" << std::endl; 
	std::cout << "> ";
	std::getline(std::cin, input);
    harl.complain(input);
    return 0;
}