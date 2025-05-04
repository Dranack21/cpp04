#include "AMateria.hpp"


AMateria::AMateria(): _type("Unknown Dark magic")
{
	std::cout << "AMateria constructor called" << std::endl;
}
AMateria::AMateria(std::string &str): _type(str)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "AMateria copy constructor called"<< std::endl;;
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	this->_type = other._type;
	return (*this);
}

const std::string &AMateria::getType()const
{
	return (this->_type);
}