#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();


const WrongAnimal* wmeta = new WrongAnimal();
const WrongAnimal* wi = new WrongCat();

std::cout << wmeta->getType() << " " << std::endl;
std::cout << wi->getType() << " " << std::endl;
wmeta->makeSound();
wi->makeSound();

delete meta;
delete j;
delete i;
delete wmeta;
delete wi;

return 0;
}