#pragma once

#include "Form.hpp"
#include <cstdlib>

class PresidentialPardonForm : public Form
{
	private :
		std::string	target_;

	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& ori);
		~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);

		void	forgive() const;
		void	executeChildren() const;
};