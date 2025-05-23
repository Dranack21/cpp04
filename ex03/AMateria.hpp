#pragma once

#include <iostream>
#include "Icharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria &other);
		AMateria	&operator=(const AMateria &other);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};