#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	ShrubberyCreationForm test("Test.txt");
	Bureaucrat testExec("John", 1);
	// testExec.signForm(test);
	testExec.executeForm(test);
}