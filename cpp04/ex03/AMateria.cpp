#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "AMateria";
}

AMateria::~AMateria()
{

}

AMateria::AMateria(const AMateria& ref)
{
	this->type = ref.type;
}

AMateria &AMateria::operator=(const AMateria& ref)
{
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "It is empty. Can not attack " << target.getName() << "." << std::endl;
}
