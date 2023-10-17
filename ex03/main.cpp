#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main( void )
{
	Bureaucrat	testExec("Johnny Depp", 1);
	Intern someRandomIntern;
	AForm* rrf;
	try
	{
		// "shrubbery creation", "robotomy request", "presidential pardon"
		rrf = someRandomIntern.makeForm("shrubbery creation", "shrub.txt");
		testExec.signForm(*rrf);
		testExec.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "John");
		testExec.signForm(*rrf);
		testExec.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Doe");
		testExec.signForm(*rrf);
		testExec.executeForm(*rrf);
		delete rrf;
		std::cout << "Everything passed successfully!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
