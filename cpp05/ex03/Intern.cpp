#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string name, const std::string target) const
{
    std::string arr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    typedef AForm* (Intern::*functionPointer)(std::string) const;

    const functionPointer functionArray[3] = {&Intern::makeShrubberyCreationForm,
                                              &Intern::makeRobotomyRequestForm,
                                              &Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; i++)
    {
        if (name == arr[i])
            return (this->*functionArray[i])(target);
    }
	throw FormNotFoundException();
}

AForm* Intern::makeShrubberyCreationForm(std::string target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(std::string target) const
{
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() { return ("Form Not Found"); }

