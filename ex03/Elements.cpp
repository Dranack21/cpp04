#include "Elements.hpp"


Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice &other): AMateria(other)
{
	*this = other;
}
Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
    {
        AMateria::operator=(copy);
        this->_type = copy._type;
    }
	return (*this);
}

Ice::~Ice()
{
	
}

void Ice::use(ICharacter &target)
{
	std::cout << "shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria *Ice::clone()const
{
	AMateria *yippe = new Ice();
	return (yippe);
}



Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(const Cure &other): AMateria(other)
{
	*this = other;
}
Cure &Cure::operator=(const Cure &copy)
{
	this->_type = copy._type;
	return (*this);
}

Cure::~Cure()
{

}

void Cure::use(ICharacter &target)
{
	std::cout << "Cures " << target.getName() << " wounds" << std::endl;
}

AMateria *Cure::clone()const
{
	AMateria *yippe = new Cure();
	return (yippe);
}
