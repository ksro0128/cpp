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
		virtual void		makeSound() const;
		virtual std::string	getType() const;
	private:
		std::string type;
};

#endif