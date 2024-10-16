#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw GradeTooHighException("Grade is too high");
	}
	else if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw GradeTooLowException("Grade is too low");
	}
}

const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form Details:" << std::endl
	   << "Name: " << form.getName() << std::endl
	   << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl
	   << "Grade to Sign: " << form.getGradeToSign() << std::endl
	   << "Grade to Execute: " << form.getGradeToExecute() << std::endl;
	return os;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
    {
        throw GradeTooLowException("Grade too low to sign the form");
    }
    this->isSigned = true;
}