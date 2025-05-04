#pragma once

#include "Animal.hpp"

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &other);

		void setIdea(int const index, std::string const &idea);
		std::string getIdea(int const index);
};