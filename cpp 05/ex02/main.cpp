#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
	try
	{
		Bureaucrat bureaucrat("John Doe", 1);
		RobotomyRequestForm form2("home2");
		ShrubberyCreationForm form("home");
		PresidentialPardonForm form3("home3");
		bureaucrat.signForm(form2);
		bureaucrat.executeForm(form2);
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.signForm(form3);
		bureaucrat.executeForm(form3);

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}