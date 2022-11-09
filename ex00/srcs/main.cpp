#include "bureaucrat.hpp"
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
			Bureaucrat a("Obelix", 127);
			Bureaucrat b("Asterix", 4);
			std::cout << "Testing accessors..." << std::endl;
			std::cout << std::endl;
			std::cout << "My name is " << a.getName() << " and my grade is "
				<< a.getGrade() << std::endl;
			std::cout << "My name is " << b.getName() << " and my grade is "
				<< b.getGrade() << std::endl;
			std::cout << "Testing << overload..." << std::endl;
			std::cout << a << std::endl;
			std::cout << b << std::endl;

		}
		else if (arg == "2")
		{
			std::cout << ORANGERED1 << "TEST #2" << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing setting a grade too low..." << std::endl;
			std::cout << std::endl;
			Bureaucrat c("Tolow", 151);
			std::cout << "My name is " << c.getName() << " and my grade is "
				<< c.getGrade() << std::endl;
		}
		else if (arg == "3")
		{
			std::cout << ORANGERED1 << "TEST #3" << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << "Testing setting a grade too high..." << std::endl;
			std::cout << std::endl;
			Bureaucrat d("Tohigh", 0);
			std::cout << "My name is " << d.getName() << " and my grade is "
				<< d.getGrade() << std::endl;
		}
		else if (arg == "4")
		{
			std::cout << ORANGERED1 << "TEST #4" << RESET << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cout << std::endl;
			Bureaucrat e("Jeff", 2);
			std::cout << e << std::endl;
			std::cout << "Testing incrementing..." << std::endl;
			std::cout << std::endl;
			e.increment();
			std::cout << e << std::endl;
			e.increment();
			std::cout << e << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return 0;
}