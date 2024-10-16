#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
class Data
{
private :
    std::string _name;
    int         _age;
public :
    std::string             getName() const;
    void                    setName(std:: string name);

    int                     getAge() const;
    void                    setAge(int  age);

};


#endif