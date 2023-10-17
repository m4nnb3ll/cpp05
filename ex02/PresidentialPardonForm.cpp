#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("Presidential", 25, 5), m_target("Undefined")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:	AForm("Presidential", 25, 5), m_target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form)
	:	AForm(form), m_target(form.m_target)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getSigned()))
		throw(AForm::NotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
