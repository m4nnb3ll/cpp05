#pragma once

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& form);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& form);
	void	execute(const Bureaucrat& executor) const;
private:
	const std::string	m_target;
};
