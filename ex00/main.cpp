#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

int main()
{
	{
		std::cout << "### TESTING ANIMAL ####" << std::endl << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "j type is "<< j->getType() << " " << std::endl;
		std::cout << "i type is " << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete i;
		delete j;
		delete meta;
	}
	{
		std::cout << std::endl << "### TESTING WRONG ANIMAL ####" << std::endl << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << "i type is " << i->getType() << " " << std::endl;
		i->makeSound(); //will NOT output the cat sound because we didnt add VIRTUAL BEFOER FUNCTION MAKESOUND!
		meta->makeSound();

		delete meta;
		delete i;
	}
}
