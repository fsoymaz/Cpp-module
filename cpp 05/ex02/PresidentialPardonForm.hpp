#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm();
	virtual void execute(Bureaucrat const &executor) const;
	
};