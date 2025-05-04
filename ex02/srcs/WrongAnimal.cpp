#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("default")
{
	std::cout << "WrongAnimal Constructor has been called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy constructor has been called " << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal operator overload called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return (*this);
}

void WrongAnimal::makeSound()const
{
	std::cout << this->getType() << " is not a Animal" << std::endl;
}
std::string WrongAnimal::getType()const
{
	return(this->type);
}