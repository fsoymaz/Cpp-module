#pragma once
#include <iostream>

class Bureaucrat {
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);

	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

class GradeTooHighException : public std::exception {
private:
	std::string message;
public:
	GradeTooHighException(const std::string& msg) : message(msg) {}
	~GradeTooHighException() throw() {}
	const char* what() const throw() {
		return message.c_str();
	}
};

class GradeTooLowException : public std::exception {
private:
	std::string message;
public:
	GradeTooLowException(const std::string& msg) : message(msg) {}
	~GradeTooLowException() throw() {}
	const char* what() const throw() {
		return message.c_str();
	}
};
