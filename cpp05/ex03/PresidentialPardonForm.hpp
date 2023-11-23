#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		PresidentialPardonForm&	operator=(PresidentialPardonForm ref);
		void	execute(Bureaucrat const & executor) const;
	private:
		PresidentialPardonForm();
};

#endif