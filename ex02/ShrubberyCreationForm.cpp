#include "ShrubberyCreationForm.hpp"
#include <fstream>

# define SHRUB_ASCII "\
                     .o00o\n\
                   o000000oo\n\
                  00000000000o\n\
                 00000000000000\n\
              oooooo  00000000  o88o\n\
           ooOOOOOOOoo  ```''  888888\n\
         OOOOOOOOOOOO'.qQQQQq. `8888'\n\
        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n\
        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n\
         OOOOOOOOO QQQQQQQQQQ/ /QQ\n\
           OOOOOOOOO `QQQQQQ/ /QQ'\n\
             OO:F_P:O `QQQ/  /Q'\n\
                \\. \\ |  // |\n\
                d\\ \\\\|_////\n\
                qP| \\ _' `|Ob\n\
                   \\  / \\  \\Op\n\
                   |  | O| |\n\
           _       /\\. \\_/ /\n\
            `---__/|_\\   //|  __\n\
                  `-'  `-'`-'-'\n\
"



const char*	ShrubberyCreationForm::ErrorOpeningFileException::what() const _NOEXCEPT
{
	return "There was a problem opening the file for reading.";
}

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("Shrubbery", 145, 137), m_target("Undefined")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:	AForm("Shrubbery", 145, 137), m_target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
	:	AForm(form), m_target(form.m_target)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!(this->getSigned()))
		throw(AForm::NotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	std::ofstream	outputFile(m_target);
	if (!outputFile.is_open())
		throw(ShrubberyCreationForm::ErrorOpeningFileException());
	outputFile << SHRUB_ASCII;
	outputFile.close();
}