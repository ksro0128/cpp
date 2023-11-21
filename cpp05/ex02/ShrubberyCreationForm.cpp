#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref.getName(), ref.getGradeTosign(), ref.getGradeToExecute())
{

}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	if (this != &ref)
	{
		const_cast<std::string&>(_name) = ref._name;
		const_cast<int&>(_gradeToSign) = ref._gradeToSign;
		const_cast<int&>(_gradeToExecute) = ref._gradeToExecute;
		_isSigned = ref._isSigned;
	}
	return (*this);
}

void		ShrubberyCreationForm::beSigned(const Bureaucrat& a)
{
	if (a.getGrade() <= _gradeToSign)
	{
		std::ofstream ofs;

		ofs.open(_name + "_shrubbery");
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
