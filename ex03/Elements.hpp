#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();
	
		void use(ICharacter& target);
		virtual AMateria *clone() const;
};

class Cure : public AMateria
{
	private:
	public:
		Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();
	
		void use(ICharacter& target);
		virtual AMateria *clone() const;
};