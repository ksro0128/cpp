#include "Brain.hpp"

Brain::Brain()
{
	this->n = 0;
	std::cout << "Brain Class Constructor has been called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Class Destructor has been called" << std::endl;
}

Brain::Brain(const Brain& ref)
{
	std::cout << "Brain Class Copy Constructor has been called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = ref.ideas[i];
	}
}

Brain &Brain::operator=(const Brain& ref)
{
	std::cout << "Brain Class Copy Assignment Operator has been called" << std::endl;
	if (this != &ref)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = ref.ideas[i];
		}
	}
	return (*this);
}

void	Brain::addIdea(std::string idea)
{
	this->ideas[this->n] = idea;
	this->n += 1;
	if (this->n == 100)
		this->n = 0;
}

std::string Brain::getIdea(int n)
{
	if (this->ideas[n].length() == 0)
		return ("empty");
	else
		return (this->ideas[n]);
}