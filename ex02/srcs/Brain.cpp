#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor has been called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor has been called" << std::endl;
}
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return(*this);
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor has been called" << std::endl;
	*this = copy;
}


std::string Brain::getIdea(int const index) 
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return (this->ideas[0]);
}

void Brain::setIdea(int const index, std::string const  &idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}