#pragma once

# include <iostream>

class Bureaucrat
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
private:
	const std::string	m_name;
	unsigned int		m_grade;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
public:
    const char* what() const _NOEXCEPT;
};

class Bureaucrat::GradeTooLowException : public std::exception
{
public:
    const char* what() const _NOEXCEPT;
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat &b);