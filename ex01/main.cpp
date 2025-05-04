#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"




int main()
{
	{
		Animal* array[10];
		
		std::cout << "\n--- Creating Cats ---\n" << std::endl;
		for (int i = 0; i < 5; i++)
		array[i] = new Cat();
		
		std::cout << "\n--- Creating Dogs ---\n" << std::endl;
		for (int i = 5; i < 10; i++)
		array[i] = new Dog();
		for(int i = 0; i < 10; i++)
		{
			std::cout << "Animal type is : "<< array[i]->getType() << std::endl;
			array[i]->makeSound();
		}
		for (int i = 0; i < 10; i++)
		delete array[i];
	}

	{
		std::cout << "\n### TESTING DEEP COPY ###\n" << std::endl;
		Cat* gatito = new Cat;
		gatito->setIdea(0, "pee on the floor\n");
		Cat* katt = new Cat(*gatito);
		std::cout << "\ngatito idea before change 0: " << gatito->getIdea(0) << std::endl;
		std::cout << "katt idea before change 0: " << katt->getIdea(0) << std::endl;
		gatito->setIdea(0, "Break a vase\n");

		std::cout << "\ngatito idea 0 after change : " << gatito->getIdea(0) << std::endl;
		std::cout << "katt idea 0 after change: " << katt->getIdea(0) << std::endl;

		delete gatito;
		delete katt;
	}

}


