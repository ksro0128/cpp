#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal Class Constructor has been called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Class Destructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
	std::cout << "WrongAnimal Class Copy Constructor has been called" << std::endl;
	this->type = ref.getType();
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& ref)
{
	std::cout << "WrongAnimal Class Copy Assignment Operator has been called" << std::endl;
	if (this != &ref)
		this->type = ref.getType();
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}