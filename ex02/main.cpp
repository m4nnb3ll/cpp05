#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	ShrubberyCreationForm test("Test.txt");
	Bureaucrat testExec("John", 1);
	testExec.signForm(test);
	testExec.executeForm(test);

	RobotomyRequestForm test1("Doe");
	Bureaucrat testExec1("jack", 1);
	testExec.signForm(test1);
	testExec.executeForm(test1);

	PresidentialPardonForm test2("barbie");
	Bureaucrat testExec2("oppenheimer", 1);
	testExec.signForm(test2);
	testExec.executeForm(test2);

	
}
