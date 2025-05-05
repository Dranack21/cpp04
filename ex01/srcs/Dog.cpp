#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog Constructor has been called" << std::endl;
	this->_brain = new Brain;
	this->type = "Dog";
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog Destructor has been called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	this->_brain = new Brain;
    *(this->_brain) = *(copy._brain);
	std::cout << "Dog Copy constructor has been called " << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);

		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain); // Deep copy
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound()const
{
	std::cout << this->getType() << " Says Woof" << std::endl;
}


std::string Dog::getIdea(int index)
{
	return(this->_brain->getIdea(index));
}

void Dog::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}