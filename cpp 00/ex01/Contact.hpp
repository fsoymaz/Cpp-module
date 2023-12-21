#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

  public:
	void setFirstName(std::string);
	void setLastName(std::string);
	void setNickName(std::string);
	void setPhoneNumber(std::string);
	void setDarkSecret(std::string);

	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkSecret();
};

#endif