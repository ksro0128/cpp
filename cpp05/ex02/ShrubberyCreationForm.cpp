#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref.getName(), ref.getGradeTosign(), ref.getGradeToExecute())
{
	setSign(ref.getIsSigned());
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm ref)
{
	swap(ref);
	return (*this);
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false)
		throw (NotSignedException());
	else if (getGradeToExecute() < executor.getGrade())
		throw (GradeTooLowException());
	else
	{
		std::ofstream ofs;
		ofs.open(getName() + "_shrubbery");
		ofs << "    oxoxoo    ooxoo" << std::endl;
		ofs << "  ooxoxo oo  oxoxooo" << std::endl;
		ofs << " oooo xxoxoo ooo ooox" << std::endl;
		ofs << " oxo o oxoxo  xoxxoxo" << std::endl;
		ofs << "  oxo xooxoooo o ooo" << std::endl;
		ofs << "    ooo\\oo\\  /o/o" << std::endl;
		ofs << "        \\  \\/ /" << std::endl;
		ofs << "         |   /" << std::endl;
		ofs << "         |  |" << std::endl;
		ofs << "         | D|" << std::endl;
		ofs << "         |  |" << std::endl;
		ofs << "         |  |" << std::endl;
		ofs << "  ______/____\\____" << std::endl;
		ofs.close();
	}
}
