#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("Robotomy", 72, 45), m_target("Undefined")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:	AForm("Robotomy", 72, 45), m_target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
	:	AForm(form), m_target(form.m_target)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getSigned()))
		throw(AForm::NotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	std::cout << "* Making some drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << m_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
