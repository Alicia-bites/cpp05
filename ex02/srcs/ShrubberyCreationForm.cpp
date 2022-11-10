#include "ShrubberyCreationForm.hpp"

// default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
: Form("unamed", 145, 137)
, target_("unamed")
{
	// std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

// Param1 constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", 145, 137)
, target_(target)
{}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& ori)
: Form(ori)
{}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

// OPERATORS OVERLOAD ---------------------------------------------------------------------------------
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	Form::operator=(rhs);
	return *this;
}

// MEMBER FUNCTIONS ---------------------------------------------------------------------------------

void	ShrubberyCreationForm::createFile() const
{
	std::ofstream	newFile;
	std::string 	name = target_ + "_shrubbery";

	std::cout << SLATEBLUE1 << "Creating new file named : " << name
		<< RESET << std::endl;
	newFile.open(name.c_str(), std::ios::out | std::ios::trunc);
	if (!newFile.good())
	{
		std::cout << RED1 << "An error occured while opening file." << RESET << std::endl;
	}
	newFile <<    
	"                                ###############\n"
	"				###############################################\n"
	"			#######################################################\n"
	"		##############################################################\n"
	"		##############################################################\n"
	"		##############################################################\n"
	"		##############################################################\n"
	"			#######################################################\n"
	"				###############################################\n"
    "                               ###############\n"
	"							   		HHHHH\n"
	"							   		HHHHH\n"
	"							   		HHHHH\n"
	"						HHHH		HHHHH\n"
	"					HHH 	HHHHHH	HHHHH\n"
	"							   	HHHHHHHHH\n"
	"							   		HHHHH\n"
	"							   		HHHHH	  HH\n"
	"							   		HHHHH   HH\n"
	"							   		HHHHHHHH\n"
	"							   		HHHHH\n"
	"							   	MKnkKMmMkHhkmM\n"
	"							Mnmknmknmkmnkmknknkmmkm\n";

	newFile.close();
}								

void	ShrubberyCreationForm::executeChildren() const
{
	createFile();
}
