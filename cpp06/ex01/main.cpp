#include <iostream>
#include "Data.hpp"

uintptr_t   serialize( Data *data ) 
{
    return ( reinterpret_cast< uintptr_t >( data ) );
}

Data*       deserialize( uintptr_t data ) 
{
    return ( reinterpret_cast< Data* >( data ) );
}

int main( void )
{
    Data *data = new Data;
    //int *ptr;

    data->setName("Yaso");
    data->setAge(26);

    //ptr = reinterpret_cast< int* >( serialize( data ));
    std::cout << "Integer Memory Address: " << serialize( data ) << std::endl;
    //std::cout << "Original Memory Address: " << ptr << std::endl;
    std::cout << "Name: " << deserialize( serialize( data ) )->getName() << std::endl;
    std::cout << "Age: " << deserialize( serialize( data ) )->getAge() << std::endl;

    delete data;

    return 0;
}