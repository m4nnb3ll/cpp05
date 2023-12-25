#pragma once

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
public:
	AForm();
	AForm(const std::string &name, unsigned int signGrade, unsigned int execGrade);
	virtual ~AForm();
	AForm(const AForm& form);
	AForm&						operator=(const AForm& form);
	class						GradeTooHighException;
	class						GradeTooLowException;
	class						NotSignedException;
	virtual const std::string&	getName() const;
	virtual bool				getSigned()  const;
	virtual unsigned int	getSignGrade() const;
	virtual unsigned int	getExecGrade() const;
	virtual void				beSigned(const Bureaucrat& bureaucrat);
	virtual void				execute(const Bureaucrat& executor) const = 0;
private:
	const std::string	m_name;
	bool				m_signed;
	const unsigned int	m_signGrade;
	const unsigned int	m_execGrade;
};

class AForm::GradeTooHighException : public std::exception
{
public:
    const char* what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
public:
    const char* what() const throw();
};

class AForm::NotSignedException : public std::exception
{
public:
    const char* what() const throw();
};


std::ostream&	operator<<(std::ostream& o, const AForm &f);