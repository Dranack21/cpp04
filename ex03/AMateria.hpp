#pragma once

#include <iostream>
#include "Icharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string &str);
		~AMateria();
		AMateria(const AMateria &other);
		AMateria	&operator=(const AMateria &other);
		AMateria(std::string const & type);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};