

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private :
		std::string const 	name_;
		int					grade_;
	public:
		Bureaucrat();
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(Bureaucrat const& ori);
		~Bureaucrat();
		Bureaucrat&	operator=(Bureaucrat const& rhs);

		std::string const&	getName() const;
		int					getGrade() const;

		void				setGrade(int grade);
	
		void				increment();
		void				decrement();

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		// ex01 add-ons :
		void	signForm(Form& form);
		//ex02 add-ons
		void	execute(Form const& form) const;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);

#endif