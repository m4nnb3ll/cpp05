#pragma once

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern( void );
	~Intern();
	Intern( const Intern &i );
	Intern&	operator=( const Intern &i );
	AForm*			makeForm( const std::string& form, const std::string& target );
	static AForm*	makeShrubbery(const std::string& target);
	static AForm*	makeRobotomy(const std::string& target);
	static AForm*	makePresidential(const std::string& target);
};
