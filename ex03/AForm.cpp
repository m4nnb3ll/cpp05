#include "AForm.hpp"


const char*	AForm::GradeTooHighException::what() const throw()
{
	return "The grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "The grade is too low!";
}

const char*	AForm::NotSignedException::what() const throw()
{
	return "The form is not signed yet!";
}

std::ostream&	operator<<(std::ostream& o, const AForm &f)
{
	o << "Details of form:\nName: " << f.getName() << " ";
	o << "SignedStatus: " << f.getSigned() << " ";
	o << "SignGrade: " << f.getSignGrade() << " ";
	o << "ExecGrade: " << f.getExecGrade() << std::endl;
	return (o);
}

AForm::AForm()
	:	m_name("Undefined"),
		m_signed(false),
		m_signGrade(1),
		m_execGrade(1)
{
}

AForm::AForm(const std::string &name, unsigned int signGrade, unsigned int execGrade)
	:	m_name(name),
		m_signed(false),
		m_signGrade(signGrade),
		m_execGrade(execGrade)
{
	if (m_signGrade < 1 || m_execGrade < 1)
		throw(AForm::GradeTooHighException());
	else if (m_signGrade > 150 || m_execGrade > 150)
		throw(AForm::GradeTooLowException());
}

AForm::~AForm()
{
	std::cout << "AForm destructor called!" << std::endl;
}

AForm::AForm(const AForm& form)
	:	m_name(form.m_name),
		m_signed(form.m_signed),
		m_signGrade(form.m_signGrade),
		m_execGrade(form.m_execGrade)
{
}

AForm&	AForm::operator=(const AForm& form)
{
	if (this != &form)
		this -> m_signed = form.m_signed;
	return (*this);
}

const std::string&	AForm::getName() const
{
	return (m_name);
}

bool	AForm::getSigned()  const
{
	return (m_signed);
}

const unsigned int	AForm::getSignGrade() const
{
	return (m_signGrade);
}

const unsigned int	AForm::getExecGrade() const
{
	return (m_execGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= m_signGrade)
		m_signed = true;
	else
		throw(AForm::GradeTooLowException());
}