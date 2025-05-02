#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog Constructor has been called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor has been called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	std::cout << "Dog Copy constructor has been called " << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	std::cout << "Dog assignement operator called" << std::endl;
	return(*this);
}

void Dog::makeSound()const
{
	std::cout << this->getType() << " Says Woof" << std::endl;
}
