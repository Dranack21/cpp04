#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[4];
	public:
	   // Constructors
	   MateriaSource();
	   MateriaSource(const MateriaSource &copy);
	   MateriaSource &operator=(const MateriaSource &other);
	   ~MateriaSource();
   
	   // Getters & Setters
	   // Functions
		void learnMateria(AMateria *materia);
		AMateria *createMateria(std::string const& type);
   
};