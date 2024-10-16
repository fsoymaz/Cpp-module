#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
	std::string target;

public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target);
	const std::string &getName() const;

	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

class FormNotSignedException : public std::exception
{
private:
	std::string message;

public:
	FormNotSignedException(const std::string &msg) : message(msg) {}
	~FormNotSignedException() throw() {}
	const char *what() const throw()
	{
		return message.c_str();
	}
};
