#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
:name_("none")
, grade_(0)
{}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
: name_(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	grade_ = grade;
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
	o << rhs.getName() <<  ", bureaucrat grade "
		<< rhs.getGrade() << ".";
	return o;
}

// MEMBER FUNCTIONS ----------------------------------

void	Bureaucrat::increment()
{
	std::cout << "Incrementing " << name_ << "'s grade"
		<< std::endl;
	if (grade_ - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade_ -= 1;
}

void	Bureaucrat::decrement()
{
	std::cout << "Decrementing " << name_ << "'s grade"
		<< std::endl;
	if (grade_ + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade_ += 1;

}

void	Bureaucrat::signForm(Form& form)
{
	// if (form.getSigned)
	// 	std::cout << name_ << " signed" << form << std::endl;
	// else
	// 	std::cout << name_ << " couldn 't sign form because his grade is too low."
	// 		<< std::endl;

	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Must be < 150 and > 1. 150 being the lowest rank.";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Must be < 150 and > 1. 1 being the highest rank.";
}