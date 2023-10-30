#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Class Constructor has been called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Class Destructor has been called" << std::endl;
}

Cat::Cat(const Cat& ref)
{
	std::cout << "Cat Class Copy Constructor has been called" << std::endl;
	this->type = ref.getType();
	this->brain = new Brain(*ref.getBrain());
}

Cat &Cat::operator=(const Cat& ref)
{
	std::cout << "Cat Class Copy Assignment Operator has been called" << std::endl;
	if (this != &ref)
	{
		this->type = ref.getType();
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*ref.getBrain());
	}
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

Brain	*Cat::getBrain() const
{
	return (this->brain);
}

void	Cat::addIdea(std::string idea)
{
	this->brain->addIdea(idea);
}

std::string	Cat::getIdea(int n)
{
	return (this->brain->getIdea(n));
}