#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}
  
MateriaSource::MateriaSource(const MateriaSource &copy) 
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._materias[i]) 
		{
			this->_materias[i] = copy._materias[i]->clone();
		}
		else
			this->_materias[i] = NULL;
	}
}
  
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i) 
		{
			if (this->_materias[i])
				delete this->_materias[i];
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return *this;
}
  // Destructor
MateriaSource::~MateriaSource() 
{
	for (int i = 0; i < 4; i++) 
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = materia;
			std::cout << "Materia source learned " << materia->getType() << " on slot " << i <<" !" << std::endl;
		  	return;
		}
	}
	std::cout << "Couldn't learn " << materia->getType() << ", because materia source is full." << std::endl;
	delete materia;
}
AMateria *MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	std::cout << "Unknown Materia type: " << type << std::endl;
	return NULL;
}