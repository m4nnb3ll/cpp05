#pragma once

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& form);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& form);
	void	execute(const Bureaucrat& executor) const;
	class	ErrorOpeningFileException;
private:
	const std::string	m_target;
};

class ShrubberyCreationForm::ErrorOpeningFileException : public std::exception
{
public:
    const char* what() const _NOEXCEPT;
};