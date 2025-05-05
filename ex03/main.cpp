#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Elements.hpp"

int main()
{
	// std::cout << "Creating MateriaSource..." << std::endl;
	IMateriaSource* src = new MateriaSource();

	// std::cout << "Learning Ice Materia..." << std::endl;
	src->learnMateria(new Ice());

	// std::cout << "Learning Cure Materia..." << std::endl;
	src->learnMateria(new Cure());

	// std::cout << "Creating Character 'me'..." << std::endl;
	ICharacter* me = new Character("Jojo");

	AMateria* tmp;

	// std::cout << "Creating Ice Materia from source..." << std::endl;
	tmp = src->createMateria("ice");
	// std::cout << "Equipping Ice Materia to 'me'..." << std::endl;
	me->equip(tmp);

	// std::cout << "Creating Cure Materia from source..." << std::endl;
	tmp = src->createMateria("cure");
	// std::cout << "Equipping Cure Materia to 'me'..." << std::endl;
	me->equip(tmp);

	// std::cout << "Creating Character 'bob'..." << std::endl;
	ICharacter* bob = new Character("bob");

	// std::cout << "'me' uses Ice Materia on 'bob'..." << std::endl;
	me->use(0, *bob);

	// std::cout << "'me' uses Cure Materia on 'bob'..." << std::endl;
	me->use(1, *bob);

	// std::cout << "Deleting 'bob'..." << std::endl;
	delete bob;

	// std::cout << "Deleting 'me'..." << std::endl;
	delete me;

	// std::cout << "Deleting MateriaSource..." << std::endl;
	delete src;

	// std::cout << "Exiting program..." << std::endl;
	return 0;
}