#pragma once

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
public:
	Form();
	Form(const std::string &name, unsigned int signGrade, unsigned int execGrade);
	~Form();
	Form(const Form& form);
	Form&				operator=(const Form& form);
	class				GradeTooHighException;
	class				GradeTooLowException;
	const std::string&	getName() const;
	bool				getSigned()  const;
	unsigned int	getSignGrade() const;
	unsigned int	getExecGrade() const;
	void				beSigned(const Bureaucrat& bureaucrat);
private:
	const std::string	m_name;
	bool				m_signed;
	const unsigned int	m_signGrade;
	const unsigned int	m_execGrade;
};

class Form::GradeTooHighException : public std::exception
{
public:
    const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
public:
    const char* what() const throw();
};

std::ostream&	operator<<(std::ostream& o, const Form &f);