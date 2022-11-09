#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		std::string const	name_;
		bool				signed_;
		int const			gradeSign_; // 150 to 1
		int const			gradeEx_; // 150 to 1
	public :
		Form();
		Form(std::string name, int gradeSign_, int gradeEx);
		Form(Form const& ori);
		~Form();
		Form& operator=(Form const& rhs);

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeEx() const;

		void				beSigned(Bureaucrat& bureaucrat);

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

std::ostream&	operator<<(std::ostream& o, Form const& rhs);