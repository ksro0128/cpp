#include "Cat.hpp"
#include "Dog.hpp"

void leaks()
{
	system("leaks a.out");
}

int main()
{
	atexit(leaks);
	std::cout << "first test" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl << std::endl << "second test" << std::endl;
	Animal *array[6];
	for (int i = 0; i < 3; i++)
		array[i] = new Cat();
	std::cout << std::endl;
	for (int i = 3; i < 6; i++)
		array[i] = new Dog();
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
		delete array[i];


	std::cout << std::endl << std::endl << "third test" << std::endl;
	Cat c;
	Cat c_copy;
	
	c.addIdea("first idea");
	c.addIdea("second idea");
	c_copy = c;
	c.addIdea("third idea");
	std::cout << "c : " << c.getIdea(0) << ", " << c.getIdea(1) << ", " << c.getIdea(2) << std::endl;
	std::cout << "c_copy : " << c_copy.getIdea(0) << ", " << c_copy.getIdea(1) << ", " << c_copy.getIdea(2) << std::endl;


	return 0;
}
