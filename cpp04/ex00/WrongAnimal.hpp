#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& ref);
		WrongAnimal& operator=(const WrongAnimal& ref);
		void		makeSound() const;
		virtual std::string	getType() const;
	private:
		std::string type;
};

#endif