#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
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

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form Details:" << std::endl
	   << "Name: " << form.getName() << std::endl
	   << "Is Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl
	   << "Grade to Sign: " << form.getGradeToSign() << std::endl
	   << "Grade to Execute: " << form.getGradeToExecute() << std::endl;
	return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
    {
        throw GradeTooLowException("Grade too low to sign the form");
    }
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned)
	{
		throw FormNotSignedException("Form is not signed");
	}
	if (executor.getGrade() > gradeToExecute)
	{
		throw GradeTooLowException("Grade too low to execute the form");
	}
}

std::string AForm::getTarget() const
{
	return target;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute),target(target)
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