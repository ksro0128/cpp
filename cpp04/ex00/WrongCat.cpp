#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Class Constructor has been called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Class Destructor has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref)
{
	std::cout << "WrongCat Class Copy Constructor has been called" << std::endl;
	this->type = ref.getType();
}

WrongCat &WrongCat::operator=(const WrongCat& ref)
{
	std::cout << "WrongCat Class Copy Assignment Operator has been called" << std::endl;
	if (this != &ref)
		this->type = ref.getType();
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow!" << std::endl;
}

std::string	WrongCat::getType() const
{
	return (this->type);
}