#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain& ref);
		Brain& operator=(const Brain& ref);
		void	addIdea(std::string idea);
		std::string	getIdea(int n);
		
	private:
		std::string ideas[100];
		int n;
};

#endif