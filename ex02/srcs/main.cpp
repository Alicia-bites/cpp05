

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
# define ORANGERED1 "\033[38;5;202m"
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
			std::cout << ORANGERED1 << "TEST #1" << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Creating a ShrubberyCreationForm..." << std::endl;
			ShrubberyCreationForm shrubby("treeBaby");
			std::cout << shrubby << std::endl;
			shrubby.createFile();

		}
		else if (arg == "2")
		{

		}
		else if (arg == "3")
		{
		}
		else if (arg == "4")
		{
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}