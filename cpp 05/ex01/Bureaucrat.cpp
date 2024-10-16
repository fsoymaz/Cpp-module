#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
	if (grade < 1) {
		throw GradeTooHighException("Grade is too high");
	} else if (grade > 150) {
		throw GradeTooLowException("Grade is too low");
	}
	this->grade = grade;
}
#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
    if (this != &copy) {
        this->grade = copy.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException("Grade is too high");
    }
    --grade;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException("Grade is too low");
    }
    ++grade;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::signForm(Form &form)
{
    if (grade > form.getGradeToSign())
    {
        throw GradeTooLowException("Grade too low to sign the form");
    }
    form.beSigned(*this); // call beSigned() instead of getIsSigned()
}