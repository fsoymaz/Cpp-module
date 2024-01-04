//
// Created by fatih soymaz on 28.10.2023.
//

#include "iostream"

int	main(void)
{
	std::string str = "HI THIS IS BRAİN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << str<< std::endl;
	std::cout << stringPTR<< std::endl;
	std::cout << stringREF<< std::endl;
	std::cout << *stringPTR<< std::endl;
	std::cout << &stringREF<< std::endl;
}