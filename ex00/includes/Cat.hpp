#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		~Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &other);
		void makeSound()const;
};