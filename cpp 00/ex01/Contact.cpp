#include "Contact.hpp"

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

std::string Contact::getFirstName()
{
    return firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

std::string Contact::getLastName()
{
    return lastName;
}

void Contact::setNickName(std::string _nickName)
{
    nickName = _nickName;
}

std::string Contact::getNickName()
{
    return nickName;
}


void Contact::setPhoneNumber(std::string _phoneNumber)
{
    phoneNumber = _phoneNumber;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

void Contact::setDarkSecret(std::string _darkestSecret)
{
    darkestSecret = _darkestSecret;
}

std::string Contact::getDarkSecret()
{
    return darkestSecret;
}
