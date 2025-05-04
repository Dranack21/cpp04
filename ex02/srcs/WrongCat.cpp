#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat Constructor has been called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor has been called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
	std::cout << "WrongCat Copy constructor has been called " << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	std::cout << "WrongCat assignement operator called" << std::endl;
	return(*this);
}

void WrongCat::makeSound()const
{
	std::cout << this->getType() << " Says Meow" << std::endl;
}
