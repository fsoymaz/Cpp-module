#include "Converter.hpp"

int main( int ac, char ** av )
{
    if ( ac != 2 ) {
        std::cout << "Usage: ./convert number" << std::endl;
        return 1;
    }

    Converter c;

    try
    {
        c.setStr( av[1] );
        c.convert();

        std::cout << c;
    }
    catch( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    return 0;
}