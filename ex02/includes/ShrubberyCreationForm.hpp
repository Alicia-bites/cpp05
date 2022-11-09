#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form
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

		virtual void		beSigned(Bureaucrat& bureaucrat) const = 0;

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