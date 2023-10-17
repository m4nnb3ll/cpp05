#include "Form.hpp"


const char*	Form::GradeTooHighException::what() const throw()
{
	return "The grade is too high!";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "The grade is too low!";
}

std::ostream&	operator<<(std::ostream& o, const Form &f)
{
	o << "Details of form:\nName: " << f.getName() << " ";
	o << "SignedStatus: " << f.getSigned() << " ";
	o << "SignGrade: " << f.getSignGrade() << " ";
	o << "ExecGrade: " << f.getExecGrade() << std::endl;
	return (o);
}

Form::Form()
	:	m_name("Undefined"),
		m_signed(false),
		m_signGrade(1),
		m_execGrade(1)
{
}

Form::Form(const std::string &name, unsigned int signGrade, unsigned int execGrade)
	:	m_name(name),
		m_signed(false),
		m_signGrade(signGrade),
		m_execGrade(execGrade)
{
	if (m_signGrade < 1 || m_execGrade < 1)
		throw(Form::GradeTooHighException());
	else if (m_signGrade > 150 || m_execGrade > 150)
		throw(Form::GradeTooLowException());
}

Form::~Form()
{
	std::cout << "Form destructor called!" << std::endl;
}

Form::Form(const Form& form)
	:	m_name(form.m_name),
		m_signed(form.m_signed),
		m_signGrade(form.m_signGrade),
		m_execGrade(form.m_execGrade)
{
}

Form&	Form::operator=(const Form& form)
{
	if (this != &form)
		this -> m_signed = form.m_signed;
	return (*this);
}

const std::string&	Form::getName() const
{
	return (m_name);
}

bool	Form::getSigned()  const
{
	return (m_signed);
}

const unsigned int	Form::getSignGrade() const
{
	return (m_signGrade);
}

const unsigned int	Form::getExecGrade() const
{
	return (m_execGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= m_signGrade)
		m_signed = true;
	else
		throw(Form::GradeTooLowException());
}