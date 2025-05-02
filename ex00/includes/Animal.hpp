#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		~Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &other);
	
		virtual void makeSound()const;
		std::string getType()const;
};