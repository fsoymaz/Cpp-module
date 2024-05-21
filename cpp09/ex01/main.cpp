#include "RPN.hpp"

int main(int ac, char **ag)
{
    if(ac == 2)
    {
        try
        {
            RPN a;
            a.start(ag[1]);
        }
        catch(std::exception &s)
        {
            std::cerr << "Error" << std::endl;
        }
    }
    else
        std::cerr << "Error" << std::endl;
    
}