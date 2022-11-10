#include "PresidentialPardonForm.hpp"

// default constructor
PresidentialPardonForm::PresidentialPardonForm()
: Form("unamed", 25, 5)
, target_("unamed")
{
	// std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

// Param1 constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("presidential pardon", 25, 5)
, target_(target)
{}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& ori)
: Form(ori)
{}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{}

// OPERATORS OVERLOAD ---------------------------------------------------------------------------------
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	Form::operator=(rhs);
	return *this;
}

// MEMBER FUNCTIONS ---------------------------------------------------------------------------------

void	PresidentialPardonForm::forgive() const
{
	std::cout << SALMON1 <<  "Zaphod forgave " << target_ << RESET << std::endl;
}

void	PresidentialPardonForm::executeChildren() const
{
	forgive();
}