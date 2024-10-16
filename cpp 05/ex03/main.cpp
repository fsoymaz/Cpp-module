#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    Bureaucrat bureaucrat("John Doe", 1);

    try
    {
        AForm* form = intern.makeForm("shrubbery creation", "Bender");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}