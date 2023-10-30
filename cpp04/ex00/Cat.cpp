#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Class Constructor has been called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Class Destructor has been called" << std::endl;
}

Cat::Cat(const Cat& ref)
{
	std::cout << "Cat Class Copy Constructor has been called" << std::endl;
	this->type = ref.getType();
}

Cat &Cat::operator=(const Cat& ref)
{
	std::cout << "Cat Class Copy Assignment Operator has been called" << std::endl;
	if (this != &ref)
		this->type = ref.getType();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string	Cat::getType() const
{
	return (this->type);
}