#pragma once

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
	private:
		Form	*dataBase_[3];
	public:
		Intern(void);
		Intern(Intern const&);	
		~Intern(void);
		Intern &operator=(Intern const&);

		Form	*makeForm(std::string formName, std::string formTarget);

		void	fillDataBase(std::string& target);

		class NameDoesNotExist : public std::exception
		{
			const char	*what() const throw();
		};
};
