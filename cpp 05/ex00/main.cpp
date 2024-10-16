#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("John", 150);
		std::cout << b.getName() << " has grade " << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << b.getName() << " has grade " << b.getGrade() << std::endl;
		b.incrementGrade();
		std::cout << b.getName() << " has grade " << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << b.getName() << " has grade " << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << b.getName() << " has grade " << b.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}