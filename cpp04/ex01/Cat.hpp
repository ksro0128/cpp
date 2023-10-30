#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& ref);
		Cat& operator=(const Cat& ref);
		virtual void		makeSound() const;
		virtual std::string	getType() const;
		Brain	*getBrain() const;
		void		addIdea(std::string idea);
		std::string	getIdea(int n);
	private:
		Brain	*brain;

};

#endif