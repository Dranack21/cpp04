#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &other);
		void makeSound()const;

		void		setIdea(int index, std::string idea);

		std::string	getIdea(int index);

};
