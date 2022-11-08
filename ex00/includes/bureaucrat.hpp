#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

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

		void	increment();
		void	decrement();

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
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);

#endif