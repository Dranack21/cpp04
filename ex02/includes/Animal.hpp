#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		Animal();
		std::string type;
	public:
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &other);

		virtual void makeSound() const = 0;
		std::string getType() const;
	private:
};