// #include "RobotomyRequestForm.hpp"


// const char*	RobotomyRequestForm::GradeTooHighException::what() const _NOEXCEPT
// {
// 	return "The grade is too high!";
// }

// const char*	RobotomyRequestForm::GradeTooLowException::what() const _NOEXCEPT
// {
// 	return "The grade is too low!";
// }

// std::ostream&	operator<<(std::ostream& o, const RobotomyRequestForm &f)
// {
// 	o << "Details of form:\nName: " << f.getName() << " ";
// 	o << "SignedStatus: " << f.getSigned() << " ";
// 	o << "SignGrade: " << f.getSignGrade() << " ";
// 	o << "ExecGrade: " << f.getExecGrade() << std::endl;
// 	return (o);
// }

// RobotomyRequestForm::RobotomyRequestForm()
// 	:	m_name("Undefined"),
// 		m_signed(false),
// 		m_signGrade(1),
// 		m_execGrade(1)
// {
// }

// RobotomyRequestForm::RobotomyRequestForm(const std::string &name, unsigned int signGrade, unsigned int execGrade)
// 	:	m_name(name),
// 		m_signed(false),
// 		m_signGrade(signGrade),
// 		m_execGrade(execGrade)
// {
// 	if (m_signGrade < 1 || m_execGrade < 1)
// 		throw(RobotomyRequestForm::GradeTooHighException());
// 	else if (m_signGrade > 150 || m_execGrade > 150)
// 		throw(RobotomyRequestForm::GradeTooLowException());
// }

// RobotomyRequestForm::~RobotomyRequestForm()
// {
// 	std::cout << "RobotomyRequestForm destructor called!" << std::endl;
// }

// RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
// 	:	m_name(form.m_name),
// 		m_signed(form.m_signed),
// 		m_signGrade(form.m_signGrade),
// 		m_execGrade(form.m_execGrade)
// {
// }

// RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
// {
// 	if (this != &form)
// 		this -> m_signed = form.m_signed;
// 	return (*this);
// }

// const std::string&	RobotomyRequestForm::getName() const
// {
// 	return (m_name);
// }

// bool	RobotomyRequestForm::getSigned()  const
// {
// 	return (m_signed);
// }

// const unsigned int	RobotomyRequestForm::getSignGrade() const
// {
// 	return (m_signGrade);
// }

// const unsigned int	RobotomyRequestForm::getExecGrade() const
// {
// 	return (m_execGrade);
// }

// void	RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
// {
// 	if (bureaucrat.getGrade() <= m_signGrade)
// 		m_signed = true;
// 	else
// 		throw(RobotomyRequestForm::GradeTooLowException());
// }