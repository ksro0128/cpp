#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;   
}

void identify(Base& p) 
{

    try 
	{
		A a;
        a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } 
	catch (const std::exception& e) {}

    try 
	{
		B b;
        b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } 
	catch (const std::bad_cast&) {}

    try 
	{
		C c;
        c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (const std::bad_cast&) {}
}

Base* generate()
{
	int rtime = static_cast<int>(std::time(0));
	rtime %= 3;
	switch (rtime)
	{
	case 0 :
		return new A();
	case 1 :
		return new B();
	case 2 :
		return new C();
	default :
		return NULL;
	}
}

int main()
{
	Base *x = generate();
	identify(*x);
	identify(x);
	delete x;
	return 0;
}