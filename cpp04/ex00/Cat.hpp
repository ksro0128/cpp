#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& ref);
		Cat& operator=(const Cat& ref);
		virtual void		makeSound() const;
		virtual std::string	getType() const;
	private:
		std::string type;
};

#endif