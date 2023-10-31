#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->trash[i] = NULL;
	trashidx = 0;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->trash[i] = NULL;
	trashidx = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
	for (int i = 0; i < trashidx; i++)
	{
		if (this->trash[i] != NULL)
			delete this->trash[i];
	}
}

Character::Character(const Character& ref)
{
	this->name = ref.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != 0)
		{
			this->inventory[i] = ref.inventory[i]->clone();
		}
	}
	for (int i = 0; i < ref.trashidx; i++)
	{
		if (ref.trash[i] != NULL)
			this->trash[i] = ref.trash[i]->clone();
	}
	this->trashidx = ref.trashidx;
}

Character &Character::operator=(const Character& ref)
{
	if (this != &ref)
	{
		this->name = ref.name;
		for (int i = 0; i < 4; i++)
		{
			if (ref.inventory[i] != 0)
			{
				this->inventory[i] = ref.inventory[i]->clone();
			}
		}
		for (int i = 0; i < ref.trashidx; i++)
		{
			if (ref.trash[i] != NULL)
				this->trash[i] = ref.trash[i]->clone();
		}
		this->trashidx = ref.trashidx;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << this->name << " : " << "Inventory is full." << std::endl;
}

void Character::unequip(int idx)
{
	if (this->inventory[idx] == NULL)
	{
		std::cout << this->name << " : " << "This index is empty. Can not unequip." << std::endl;
	}
	else
	{
		if (trashidx == 100)
		{
			std::cout << this->name << " : " << "Trash can is full. Can not unequip." << std::endl;
			return ;
		}
		this->trash[trashidx] = this->inventory[idx];
		this->inventory[idx] = NULL;
		this->trashidx += 1;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx] == NULL)
	{
		std::cout << this->name << " : " << "This index is empty. Can not use." << std::endl;
	}
	else
	{
		this->inventory[idx]->use(target);
	}
}
