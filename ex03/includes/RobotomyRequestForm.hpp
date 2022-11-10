#pragma once

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
	private :
		std::string	target_;

	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& ori);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);

		void	robotomise() const;
		void	executeChildren() const;

};