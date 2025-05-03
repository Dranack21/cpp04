#include "../includes/Animal.hpp"

Animal::Animal(): type("default")
{
	std::cout << "Animal Constructor has been called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor has been called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy constructor has been called " << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal operator overload called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return (*this);
}

void Animal::makeSound()const
{
	std::cout << this->getType() << " is not a Animal" << std::endl;
}

std::string Animal::getType()const
{
	return(this->type);
}