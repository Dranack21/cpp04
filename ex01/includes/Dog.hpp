#pragma once

#include "Cat.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &other);
		void makeSound()const;

		void		setIdea(int index, std::string idea);

		std::string	getIdea(int index);
};