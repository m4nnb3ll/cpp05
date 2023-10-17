#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low!";
}

Bureaucrat::Bureaucrat()
	:	m_name("Undefined"),
		m_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
	:	m_name(name)
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this -> m_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
	:	m_name(bureaucrat.m_name),
		m_grade(bureaucrat.m_grade)
{ }

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
		this -> m_grade = bureaucrat.m_grade;
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (m_name);
}

unsigned int	Bureaucrat::getGrade()  const
{
	return (m_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (m_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	m_grade--;
	std::cout << this->m_name << " got their grade incremented!" << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (m_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	m_grade++;
	std::cout << this->m_name << " got their grade decremented!" << std::endl;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cout << m_name << " couldn't sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (o);
}