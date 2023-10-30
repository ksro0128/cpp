#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Class Constructor has been called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Class Destructor has been called" << std::endl;
}

Dog::Dog(const Dog& ref)
{
	std::cout << "Dog Class Copy Constructor has been called" << std::endl;
	this->type = ref.getType();
}

Dog &Dog::operator=(const Dog& ref)
{
	std::cout << "Dog Class Copy Assignment Operator has been called" << std::endl;
	if (this != &ref)
		this->type = ref.getType();
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

std::string	Dog::getType() const
{
	return (this->type);
}