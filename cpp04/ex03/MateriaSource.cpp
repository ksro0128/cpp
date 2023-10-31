#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
		{
			delete this->inventory[i];
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (ref.inventory[i] != NULL)
		{
			this->inventory[i] = ref.inventory[i]->clone();
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource& ref)
{
	if (this != &ref)
	{
		for (int i = 0; i < 4; i++)
		{
			if (ref.inventory[i] != NULL)
			{
				this->inventory[i] = ref.inventory[i]->clone();
			}
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m->clone();
			delete m;
			return ;
		}
	}
	std::cout << "Inventory is full. Can not learn." << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL && type == this->inventory[i]->getType())
		{
			AMateria *rt = this->inventory[i]->clone();
			return (rt);
		}
	}
	std::cout << "Wrong type." << std::endl;
	return (0);
}
