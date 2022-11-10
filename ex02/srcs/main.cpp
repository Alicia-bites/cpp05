

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
			std::cout << "Testing ShrubberyCreationForm..." << std::endl;
			ShrubberyCreationForm shrubby("treeBaby");
			std::cout << shrubby << std::endl;
			shrubby.createFile();

		}
		else if (arg == "2")
		{
			std::cout << ORANGERED1 << "TEST #" << arg << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing a RobotomyRequestForm..." << std::endl;
			RobotomyRequestForm robby("Elon Musk");
			std::cout << robby << std::endl;
			robby.robotomise();
		}
		else if (arg == "3")
		{
			std::cout << ORANGERED1 << "TEST #" << arg << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing a PresidentialPardonForm..." << std::endl;
			PresidentialPardonForm pressy("Bigard");
			std::cout << pressy << std::endl;
			pressy.forgive();
		}
		else if (arg == "4")
		{
			std::cout << ORANGERED1 << "TEST #" << arg << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing bureaucrat 'execute' function..." << std::endl;
			std::cout << std::endl;

			std::cout << DEEPSKYBLUE1 << ".....Creating 3 forms ->" << RESET << std::endl;
			ShrubberyCreationForm shrubby("treeBaby");
			std::cout << shrubby << std::endl;
			RobotomyRequestForm robby("Elon Musk");
			std::cout << robby << std::endl;
			PresidentialPardonForm pressy("Bigard");
			std::cout << pressy << std::endl;

			std::cout << DEEPSKYBLUE1 << ".....Creating 1 bureaucrat -> " << RESET << std::endl;
			std::cout << "Creating 1 bureaucrat : " << std::endl;
			Bureaucrat obelix("Obelix", 1);
			std::cout << obelix << std::endl;
			std::cout << std::endl;

			std::cout << DEEPSKYBLUE1 << "Obelix will try to execute form shrubby ->" << RESET << std::endl;
			obelix.execute(shrubby);
			std::cout << std::endl;
			obelix.signForm(shrubby);
			std::cout << DEEPSKYBLUE1 << "Trying again -> " << RESET << std::endl;
			std::cout << shrubby << std::endl;
			obelix.execute(shrubby);

			std::cout << DEEPSKYBLUE1 << "Do you want to do the same tests for robby : " << RESET << std::endl;
			std::string answer;
			std::getline(std::cin, answer);
			if (answer == "yes")
			{
				std::cout << DEEPSKYBLUE1 << "Obelix will try to execute form robby ->" << RESET << std::endl;
				obelix.execute(robby);
				std::cout << std::endl;
				obelix.signForm(robby);
				std::cout << DEEPSKYBLUE1 << "Trying again -> " << RESET << std::endl;
				std::cout << robby << std::endl;
				obelix.execute(robby);
			}
			std::cout << DEEPSKYBLUE1 << "Do you want to do the same tests for pressy : " << RESET << std::endl;
			std::getline(std::cin, answer);
			if (answer == "yes")
			{
				std::cout << DEEPSKYBLUE1 << "Obelix will try to execute form pressy ->" << RESET << std::endl;
				obelix.execute(pressy);
				std::cout << std::endl;
				obelix.signForm(pressy);
				std::cout << DEEPSKYBLUE1 << "Trying again -> " << RESET << std::endl;
				std::cout << pressy << std::endl;
				obelix.execute(pressy);
			}
		}
		else if (arg == "5")
		{
			std::cout << ORANGERED1 << "TEST #" << arg << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing 'execute' function with unfitted bureaucrat..." << std::endl;
			std::cout << ".....Creating 3 forms ->" << std::endl;
			ShrubberyCreationForm shrubby("treeBaby");
			std::cout << shrubby << std::endl;
			RobotomyRequestForm robby("Elon Musk");
			std::cout << robby << std::endl;
			PresidentialPardonForm pressy("Bigard");
			std::cout << pressy << std::endl;
			std::cout << ".....Creating 1 bureaucrat -> " << std::endl;
			Bureaucrat asterix("Asterix", 150);
			std::cout << asterix << std::endl;
			std::cout << std::endl;
			asterix.execute(shrubby);
			asterix.execute(robby);
			asterix.execute(pressy);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED1 << e.what() << RESET << std::endl;
	}
	return 0;
}