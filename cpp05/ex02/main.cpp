#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat a("surkim", 1);

	AForm b = ShrubberyCreationForm("hi");

	a.signForm(b);
}