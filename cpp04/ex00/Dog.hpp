#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& ref);
		Dog& operator=(const Dog& ref);
		virtual void		makeSound() const;
		virtual std::string	getType() const;
	private:
		std::string type;
};

#endif