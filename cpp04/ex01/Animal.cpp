#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal Class Constructor has been called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Class Destructor has been called" << std::endl;
}

Animal::Animal(const Animal& ref)
{
	std::cout << "Animal Class Copy Constructor has been called" << std::endl;
	this->type = ref.getType();
}

Animal &Animal::operator=(const Animal& ref)
{
	std::cout << "Animal Class Copy Assignment Operator has been called" << std::endl;
	if (this != &ref)
		this->type = ref.getType();
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}