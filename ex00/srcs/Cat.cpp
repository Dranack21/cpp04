#include "../includes/Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat Constructor has been called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor has been called" << std::endl;
}
Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "Cat Copy constructor has been called " << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	std::cout << "cat assignement operator called" << std::endl;
	return(*this);
}

void Cat::makeSound()const
{
	std::cout << this->getType() << " Says Meow" << std::endl;
}
