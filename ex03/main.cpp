#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Elements.hpp"

int main()
{
    std::cout << "========== [ Set Materia ] ==========" << std::endl;
    std::cout << "----------- [Create MateriaSource] --------------" << std::endl;
    IMateriaSource* src = new MateriaSource();
    
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n========== [ Set Character A ] ==========" << std::endl;
    std::cout << "----------- [Character : ME] --------------" << std::endl;
    ICharacter* me = new Character("ME");
    // Equip materias to the character (me)
    std::cout << "\n========== [ TEST equip() ] ==========" << std::endl;
    std::cout << "----------- [Equip on Character ME] --------------" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);//equip fails///
    me->unequip(0);
    me->equip(tmp);
    std::cout << "----------- [Unequip on Character ME] --------------" << std::endl;
    tmp = src->createMateria("cure");
    delete tmp;

    std::cout << "\n========== [ Set Character B ] ==========" << std::endl;
    std::cout << "----------- [Character : BOB] --------------" << std::endl;
    ICharacter* bob = new Character("BOB");
    
    std::cout << "\n========== [ TEST use() ] ==========" << std::endl;
    me->use(0, *bob);//cure
    me->use(3, *bob);//ice

    std::cout << "\n========== [ Cleanup ] ==========" << std::endl;

    delete bob;
    delete me;
    delete src;

    return 0;
}

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("Jojo");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	me->unequip(1);
// 	delete bob; 
// 	delete me;
// 	delete src;
// 	return 0;
// }