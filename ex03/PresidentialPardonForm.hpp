#pragma once

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& form);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& form);
	void	execute(const Bureaucrat& executor) const;
private:
	const std::string	m_target;
};
