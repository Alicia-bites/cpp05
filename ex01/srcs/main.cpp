

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
			std::cout << "Testing accessors..." << std::endl;
			std::cout << std::endl;
			Form a38("a38", 100, 130);
			std::cout << "Name is : " << a38.getName() << std::endl;
			std::cout << "Is it signed ? 0 or 1 : " << a38.getSigned() << std::endl;
			std::cout << "GradeSign is : " << a38.getGradeSign() << std::endl;
			std::cout << "GradeEx is : " << a38.getGradeEx() << std::endl;
			std::cout << std::endl;

			std::cout << "Testing overload << " << std::endl;
			std::cout << a38 << std::endl;
		}
		else if (arg == "2")
		{
			std::cout << ORANGERED1 << "TEST #2" << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing setting a grade too low..." << std::endl;
			std::cout << std::endl;
			Form c("Tolow", 151, 4);
			std::cout << "DEBUG : YOU SHOULD'T SEE THIS" << std::endl;
			Form cp("Tolow", 4, 151);
			std::cout << "DEBUG : YOU SHOULD'T SEE THIS" << std::endl;
		}
		else if (arg == "3")
		{
			std::cout << ORANGERED1 << "TEST #3" << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing setting a grade too high..." << std::endl;
			std::cout << std::endl;
			Form d("Tohigh", 0, 6);
			std::cout << "DEBUG : YOU SHOULD'T SEE THIS" << std::endl;
			Form dp("Tohigh", 6, 0);
			std::cout << "DEBUG : YOU SHOULD'T SEE THIS" << std::endl;
		}
		else if (arg == "4")
		{
			std::cout << ORANGERED1 << "TEST #4" << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing signing process..." << std::endl;
			std::cout << std::endl;

			Bureaucrat e("Jeff", 2);
			Form a38("a38", 100, 130);

			std::cout << e << std::endl;
			std::cout << a38 << std::endl;
			std::cout << "Jeff is trying to sign form a38..." << std::endl;
			std::cout << std::endl;
			e.signForm(a38);

			Bureaucrat rosa("Rosa", 150);
			std::cout << rosa << std::endl;
			std::cout << "Rosa is trying to sign form a38." << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}