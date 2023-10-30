#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		virtual ~WrongCat();
		WrongCat(const WrongCat& ref);
		WrongCat& operator=(const WrongCat& ref);
		void		makeSound() const;
		virtual std::string	getType() const;
};

#endif