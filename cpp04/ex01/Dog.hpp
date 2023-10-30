#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& ref);
		Dog& operator=(const Dog& ref);
		virtual void		makeSound() const;
		virtual std::string	getType() const;
		Brain	*getBrain() const;
		void	addIdea(std::string idea);
		std::string	getIdea(int n);
	private:
		Brain	*brain;
};

#endif