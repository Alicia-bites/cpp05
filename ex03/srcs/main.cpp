#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

# define ORANGERED1 "\033[38;5;202m"
# define DEEPSKYBLUE1 "\033[38;5;39m"
# define RESET "\033[0m"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : ./Bureaucrat <number between 1 and 4" << std::endl;
		return 0;
	}
	std::string arg(argv[1]);
	std::cout << "Requested test #" << arg << std::endl;
	try
	{
		if (arg == "1")
		{
			std::cout << ORANGERED1 << "TEST #" << arg << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing Subject from main..." << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *rrf << std::endl;
		}
		else if (arg == "2")
		{
			std::cout << ORANGERED1 << "TEST #" << arg << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing Subject from main..." << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << *rrf << std::endl;
		}
		else if (arg == "3")
		{
			std::cout << ORANGERED1 << "TEST #" << arg << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing Subject from main..." << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			std::cout << *rrf << std::endl;
		}
		else if (arg == "4")
		{
			std::cout << ORANGERED1 << "TEST #" << arg << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing Subject from main..." << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			rrf = someRandomIntern.makeForm("GNAGNAGNAGNAAAA", "Bender");
			std::cout << *rrf << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED1 << e.what() << RESET << std::endl;
	}
	return 0;
}