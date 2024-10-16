#pragma once
#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string const & target);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const & executor) const;
	
};