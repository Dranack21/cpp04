#include "Character.hpp"

Character::Character(): 
	_nickname("default")
{
	for (int i = 0; i < 4; i++)
		Inventory[i] = NULL;
	for (int i = 0; i < 20; i++)
		BackPack[i] = NULL;
}

Character::Character(std::string str): 
	_nickname(str)
{
	for (int i = 0; i < 4; i++)
		Inventory[i] = NULL;
	for (int i = 0; i < 20; i++)
		BackPack[i] = NULL;
}
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_nickname = other._nickname;
		for (int i = 0; i < 4; ++i)
		{
			if (this->Inventory[i])
			{
				delete this->Inventory[i];
				this->Inventory[i] = NULL;
			}
			if (other.Inventory[i])
				this->Inventory[i] = other.Inventory[i]->clone();
			else
				this->Inventory[i] = NULL;
		}
		for (int i = 0; i < 20; ++i)
		{
			if (this->BackPack[i])
			{
				delete this->BackPack[i];
				this->BackPack[i] = NULL;
			}
			if (other.BackPack[i])
				this->BackPack[i] = other.BackPack[i]->clone();
			else
				this->BackPack[i] = NULL;
		}
	}
	return *this;
}


Character::Character(const Character &other)
{
	*this = other;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->Inventory[i] != NULL)
		{
			delete this->Inventory[i];
			Inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (this->BackPack[i] != NULL)
		{
			delete this->BackPack[i];
			BackPack[i] = NULL;
		}
	}
}

std::string const &Character::getName()const
{
	return(this->_nickname);
}

void Character::equip(AMateria *m)
{
	int i;


	i = 0;
	for (int x = 0; x < 4; x++)
	{
		if (this->Inventory[x] == m)
		{
			std::cout << "Can't learn the same pointer twice would lead to double free errors "<< std::endl;
			return;
		}
	}
	if (!m)
	{
		std::cout << "Can't learn a NULL POINTER probably cannot learn materia "<< std::endl;
		return ;
	}
	while (i != 4)
	{
		if (this->Inventory[i] == NULL)
		{
			std::cout << this->getName() << " Learned " << m->getType() << " on inventory slot " << i << std::endl;
			this->Inventory[i] = m;
			for (int j = 0; j < 20 ; j++)
			{
				if (m == this->BackPack[j])
					this->BackPack[j] = NULL;
			}
			break;
		}
		i++;
	}
	if (i == 4)
	{
		std::cout << this->getName() << " cannot learn " << m->getType() << " because he has no inventory slots left " << std::endl;
		i = 0;
		while (i != 20)
		{
				if (this->BackPack[i] == NULL)
					break;
				i++;
		}
		if (i != 20)
		{
			std::cout << "putting it in the backpack in slot " << i<< std::endl;
			this->BackPack[i] = m;
		}
		else
		{
			std::cout << "No more space in player inventory or backpack deleting the variable please be careful " << i<< std::endl;
			delete m;
		}
	}
}

void Character::unequip(int idx)
{
	int i = 0;

	if (idx < 0 || idx >= 4)
	{
		std::cout << "Please enter an index between 0 and 3 when trying to unequip a materia" << std::endl;
		return ;
	}
	if (this->Inventory[idx] == NULL)
	{
		std::cout << this->getName() << " Has nothing equipped on slot "<< idx << std::endl;
		return ;
	}
	while(i != 20)
	{
		if (BackPack[i] == NULL)
			break;
		i++;
	}
	if (i == 20)
	{
		std:: cout << "Cannot unequip AMAteria no more slot in the BackPack" << std::endl;
		return ;
	}
	this->BackPack[i] = this->Inventory[idx];
	std::cout << this->_nickname << " Unequipped his Materia number " << idx << std::endl;
	std::cout << "It is now in the BackPack in slot " << i << std::endl;
	this->Inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Please enter an index between 0 and 3 when trying to use a materia" << std::endl;
		return ;
	}
	if (this->Inventory[idx])
	{
		std::cout << this->_nickname << " " ;
		this->Inventory[idx]->use(target);
	}
	else if ((this->Inventory[idx]) == NULL)
		std::cout << "You have no Materia equipped on this slot" << std::endl;
}
