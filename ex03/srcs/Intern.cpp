#include "Intern.hpp"

// default constructor
Intern::Intern()
{}

// copy constructor
Intern::Intern(Intern const& ori)
{
	for (int i; i <= 2; i++)
		dataBase_[i] = ori.dataBase_[i]; 		
}

// destructor
Intern::~Intern()
{
	delete dataBase_[0];
	delete dataBase_[1];
	delete dataBase_[2];
}

// OPERATOR OVERLOAD -------------------------------------------------------
Intern	&Intern::operator=(Intern const& rhs)
{
	if (this != &rhs)
		for (int i = 0; i <= 2; i++)
			dataBase_[i] = rhs.dataBase_[i]; 
	return *this;
}

// MEMBER FUNCTIONS -------------------------------------------------------

void	Intern::fillDataBase(std::string& target)
{
	dataBase_[0] = new ShrubberyCreationForm(target);
	dataBase_[1] = new RobotomyRequestForm(target);
	dataBase_[2] = new PresidentialPardonForm(target);
}

Form	*Intern::makeForm(std::string formName, std::string formTarget)
{
	fillDataBase(formTarget);
	for (int i = 0; i <= 2; i++)
		if (formName == dataBase_[i]->getName())
		{
			std::cout << "Intern creates " << DEEPPINK3 << formName << RESET << std::endl;
			return dataBase_[i];
		}
	throw Intern::NameDoesNotExist();
}

// DEFINING EXCEPTIONS ----------------------------------

const char*	Intern::NameDoesNotExist::what() const throw()
{
	return "Name doest not exist in database.";
}
