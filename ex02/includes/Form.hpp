#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

# define SPRINGGREEN1 "\033[38;5;48m"
# define SPRINGGREEN2 "\033[38;5;42m"
# define SPRINGGREEN3 "\033[38;5;47m"
# define SPRINGGREEN4 "\033[38;5;35m"
# define SPRINGGREEN5 "\033[38;5;41m"
# define SPRINGGREEN6 "\033[38;5;29m"
# define RED1 "\033[38;5;196m"
# define STEELBLUE2 "\033[38;5;75m"
# define SLATEBLUE1 "\033[38;5;99m"
# define LIGHTSEAGREEN "\033[38;5;37m"
# define LIGHTSKYBLUE2 "\033[38;5;109m"
# define SALMON1 "\033[38;5;209m"
# define DEEPSKYBLUE1 "\033[38;5;39m"
# define RESET "\033[0m"

class Bureaucrat;

class Form
{
	private :
		std::string const	name_;
		// std::string			target_;
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

		virtual void		beSigned(Bureaucrat& bureaucrat);
		virtual void		executeChildren() const = 0;
		void				execute(Bureaucrat const& executor) const;

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

		class FormNotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& o, Form const& rhs);