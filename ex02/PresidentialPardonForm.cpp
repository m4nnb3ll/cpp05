// #include "PresidentialPardonForm.hpp"


// const char*	PresidentialPardonForm::GradeTooHighException::what() const _NOEXCEPT
// {
// 	return "The grade is too high!";
// }

// const char*	PresidentialPardonForm::GradeTooLowException::what() const _NOEXCEPT
// {
// 	return "The grade is too low!";
// }

// std::ostream&	operator<<(std::ostream& o, const PresidentialPardonForm &f)
// {
// 	o << "Details of form:\nName: " << f.getName() << " ";
// 	o << "SignedStatus: " << f.getSigned() << " ";
// 	o << "SignGrade: " << f.getSignGrade() << " ";
// 	o << "ExecGrade: " << f.getExecGrade() << std::endl;
// 	return (o);
// }

// PresidentialPardonForm::PresidentialPardonForm()
// 	:	m_name("Undefined"),
// 		m_signed(false),
// 		m_signGrade(1),
// 		m_execGrade(1)
// {
// }

// PresidentialPardonForm::PresidentialPardonForm(const std::string &name, unsigned int signGrade, unsigned int execGrade)
// 	:	m_name(name),
// 		m_signed(false),
// 		m_signGrade(signGrade),
// 		m_execGrade(execGrade)
// {
// 	if (m_signGrade < 1 || m_execGrade < 1)
// 		throw(PresidentialPardonForm::GradeTooHighException());
// 	else if (m_signGrade > 150 || m_execGrade > 150)
// 		throw(PresidentialPardonForm::GradeTooLowException());
// }

// PresidentialPardonForm::~PresidentialPardonForm()
// {
// 	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
// }

// PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form)
// 	:	m_name(form.m_name),
// 		m_signed(form.m_signed),
// 		m_signGrade(form.m_signGrade),
// 		m_execGrade(form.m_execGrade)
// {
// }

// PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
// {
// 	if (this != &form)
// 		this -> m_signed = form.m_signed;
// 	return (*this);
// }

// const std::string&	PresidentialPardonForm::getName() const
// {
// 	return (m_name);
// }

// bool	PresidentialPardonForm::getSigned()  const
// {
// 	return (m_signed);
// }

// const unsigned int	PresidentialPardonForm::getSignGrade() const
// {
// 	return (m_signGrade);
// }

// const unsigned int	PresidentialPardonForm::getExecGrade() const
// {
// 	return (m_execGrade);
// }

// void	PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
// {
// 	if (bureaucrat.getGrade() <= m_signGrade)
// 		m_signed = true;
// 	else
// 		throw(PresidentialPardonForm::GradeTooLowException());
// }