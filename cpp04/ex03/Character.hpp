#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(const Character& ref);
		Character& operator=(const Character& ref);
		std::string const & getName() const;
		void equip(AMateria * m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string name;
		AMateria *(inventory[4]);
		AMateria *(trash[100]);
		int trashidx;
};

#endif