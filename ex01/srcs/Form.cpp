#include "Form.hpp"

// default constructor
Form::Form()
: name_("unamed")
, signed_(0)
, gradeSign_(0)
, gradeEx_(0)
{}

// Param1 constructor
Form::Form(std::string name, int gradeSign, int gradeEx)
: name_(name)
, signed_(0)
, gradeSign_(gradeSign)
, gradeEx_ (gradeEx)
{
	if (gradeSign_ < 1 || gradeEx_ < 1)
		throw Form::GradeTooHighException();
	if (gradeSign_ > 150 || gradeEx_ > 150)
		throw Form::GradeTooLowException();
}

// copy constructor
Form::Form(Form const& ori)
: name_(ori.name_)
, signed_(ori.signed_)
, gradeSign_(ori.gradeSign_)
, gradeEx_(ori.gradeEx_)
{}

// destructor
Form::~Form()
{}

// OPERATOR OVERLOADS --------------------------------------

Form&	Form::operator=(Form const& rhs)
{
	// name_ = rhs.name_; // --> name_ can't copied because it's constant
	signed_ = rhs.signed_;
	// gradeSign_ = rhs.gradeSign_; // --> gradeSign_ can't copied because it's constant
	// gradeEx_ = rhs.gradeEx_; // --> gradeEx_ can't copied because it's constant
	return *this;
}

std::ostream&	operator<<(std::ostream& o, Form const& rhs)
{
	o << "Form name is : "
		<< rhs.getName()
		<< std::endl
		<< "Is it signed? 0 for no, 1 for yes --> "
		<< rhs.getSigned()
		<< std::endl
		<< "Grade required to sign : "
		<< rhs.getGradeSign()
		<< std::endl
		<< "Grade required to execute : "
		<< rhs.getGradeEx()
		<< std::endl;
	return o;
}

// MEMBER FUNCTIONS ---------------------------------------

// - GETTERS -----------------------------------------------

std::string	const Form::getName() const
{
	return name_;
}

bool	Form::getSigned() const
{
	return signed_;
}

int		Form::getGradeSign() const
{
	return gradeSign_;
}

int		Form::getGradeEx() const
{
	return gradeEx_;
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < gradeSign_)
		throw Form::GradeTooLowException();
	signed_ = 1;

}
// - SETTERS -------------------------------------------


// DEFINING EXCEPTIONS ----------------------------------

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}
