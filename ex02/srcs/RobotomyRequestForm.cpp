#include "RobotomyRequestForm.hpp"

// default constructor
RobotomyRequestForm::RobotomyRequestForm()
: Form("unamed", 72, 45)
, target_("unamed")
{
	// std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

// Param1 constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 72, 45)
, target_(target)
{}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& ori)
: Form(ori)
{}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{}

// OPERATORS OVERLOAD ---------------------------------------------------------------------------------
RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	Form::operator=(rhs);
	return *this;
}

// MEMBER FUNCTIONS ---------------------------------------------------------------------------------

void	RobotomyRequestForm::robotomise() const
{
	std::cout << LIGHTSKYBLUE2 << "Vvvvvvvvvvvvvvvvvvrrrrrrrrrrr" << RESET << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << LIGHTSEAGREEN << target_ << " was robotomized with success." << RESET << std::endl;
}

void	RobotomyRequestForm::executeChildren() const
{
	robotomise();
}

