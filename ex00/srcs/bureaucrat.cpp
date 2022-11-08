#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat()
:name_("none")
, grade_(0)
{}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
: name_(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& ori)
: name_(ori.name_)
, grade_(ori.grade_)
{}

Bureaucrat::~Bureaucrat()
{}

// OPERATOR OVERLOADS ----------------------------------

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	// name_ = rhs.name_; --> can't copy name because it's constant
	grade_ = rhs.grade_;
	return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs)
{
	o << rhs.getName() <<  " bureaucrat grade "
		<< rhs.getGrade() << "." << std::endl;
	return o;
}

// MEMBER FUNCTIONS ----------------------------------

void	Bureaucrat::increment()
{
	std::cout << "Incrementing " << name_ << "'s grade"
		<< std::endl;
	if (grade_ - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	grade_ -= 1;
}

void	Bureaucrat::decrement()
{
	std::cout << "Decrementing " << name_ << "'s grade"
		<< std::endl;
	if (grade_ + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	grade_ += 1;

}

// -- GETTERS ----------------------------------

std::string const& Bureaucrat::getName() const
{
	return name_;
}

int	Bureaucrat::getGrade() const
{
	return grade_;
}

// -- SETTERS ----------------------------------

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Setting " << name_ << "'s grade to : " << grade
		<< std::endl;
}

// DEFINING EXCEPTIONS ----------------------------------

const char *Bureaucrat::GradeTooLowException::what() const
{
	return "Grade must be above 1 at least!";
}

const char *Bureaucrat::GradeTooHighException::what() const
{
	return "Grade must be lower than or equal to 150!";
}