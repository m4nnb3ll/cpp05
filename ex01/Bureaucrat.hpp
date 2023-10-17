#pragma once

# include <iostream>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
public:
	class GradeTooHighException;
	class GradeTooLowException;
	Bureaucrat();
	Bureaucrat(const std::string &name, unsigned int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat&			operator=(const Bureaucrat& bureaucrat);
	const std::string&	getName() const;
	unsigned int		getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form& form) const;
private:
	const std::string	m_name;
	unsigned int		m_grade;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
public:
    const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
public:
    const char* what() const throw();
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat &b);