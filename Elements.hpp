#include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		void use(ICharacter& target);
		AMateria* clone();
};