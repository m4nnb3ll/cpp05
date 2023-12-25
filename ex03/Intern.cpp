#include "Intern.hpp"

Intern::~Intern(void) {}
Intern::Intern(void) {}
Intern::Intern( const Intern& i ){(void)i;}
Intern&	Intern::operator=( const Intern& i ) {(void)i; return (*this); }

AForm*	Intern::makeShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm( const std::string& form, const std::string& target )
{
	int		i;
	std::string validForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*	(*funArr[3])(const std::string& target) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

	for (i = 0; i < 3 && validForms[i] != form; i++);
	return ((i >= 0 && i < 3) ? funArr[i](target) : throw(std::runtime_error("Not a valid form!")));
}
