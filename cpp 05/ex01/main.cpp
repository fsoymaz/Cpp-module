#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("John", 2);
        std::cout << b.getName() << " has grade " << b.getGrade() << std::endl;

        Form f("Form1", 14, 13);
        std::cout << f << std::endl;
		
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
