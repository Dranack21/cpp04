#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat Constructor has been called" << std::endl;
	this->_brain = new Brain;
	this->type = "Cat";
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor has been called" << std::endl;
}
Cat::Cat(const Cat &copy): Animal(copy)
{
	this->_brain = new Brain;
	*(this->_brain) = *(copy._brain);
	std::cout << "Cat Copy constructor has been called " << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);

		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain); // Deep copy
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound()const
{
	std::cout << this->getType() << " Says Meow" << std::endl;
}


std::string Cat::getIdea(int index)
{
	return(this->_brain->getIdea(index));
}

void Cat::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}