#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::~Cure()
{

}

Cure::Cure(const Cure& ref)
{
	this->type = ref.type;
}

Cure &Cure::operator=(const Cure& ref)
{
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

AMateria *Cure::clone() const
{
	Cure *rt;

	rt = new Cure(*this);
	return (rt);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}