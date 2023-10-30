#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Class Constructor has been called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Class Destructor has been called" << std::endl;
}

Dog::Dog(const Dog& ref)
{
	std::cout << "Dog Class Copy Constructor has been called" << std::endl;
	this->type = ref.getType();
	this->brain = new Brain(*ref.getBrain());
}

Dog &Dog::operator=(const Dog& ref)
{
	std::cout << "Dog Class Copy Assignment Operator has been called" << std::endl;
	if (this != &ref)
	{
		this->type = ref.getType();
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*ref.getBrain());
	}
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

Brain	*Dog::getBrain() const
{
	return (this->brain);
}

void	Dog::addIdea(std::string idea)
{
	this->brain->addIdea(idea);
}

std::string	Dog::getIdea(int n)
{
	return (this->brain->getIdea(n));
}