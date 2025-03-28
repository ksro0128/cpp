#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& ref);
		Animal& operator=(const Animal& ref);
		virtual void		makeSound() const = 0;
		virtual std::string	getType() const;
	protected:
		std::string type;
};

#endif