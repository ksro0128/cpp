#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::~Ice()
{

}

Ice::Ice(const Ice& ref)
{
	this->type = ref.type;
}

Ice &Ice::operator=(const Ice& ref)
{
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

AMateria *Ice::clone() const
{
	Ice *rt;

	rt = new Ice(*this);
	return (rt);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}