#include "AMateria.hpp"


AMateria::AMateria(): _type("Unknown Dark magic")
{
	// std::cout << "AMateria constructor called" << std::endl;
}
AMateria::AMateria(std::string const & type): _type(type)
{
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	// std::cout << "AMateria copy constructor called"<< std::endl;;
	*this = copy;
}


AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

const std::string &AMateria::getType()const
{
	return (this->_type);
}


void AMateria::use(ICharacter &target)
{
	(void)target;
}