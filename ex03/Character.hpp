#pragma once

#include "Icharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *Inventory[4];
		std::string _nickname;
	public:
		Character();
		Character(std::string str);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
		virtual std::string const & getName()const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		AMateria *BackPack[20];
};