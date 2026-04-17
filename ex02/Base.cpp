#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base::~Base()
{
}

Base*	generate(void)
{
	int		rand = std::rand() % 3;	

	return (rand == 0) ? dynamic_cast<Base*>(new A)
		: (rand == 1) ? dynamic_cast<Base*>(new B)
		: dynamic_cast<Base*>(new C);
}

void	identify(Base* p)
{
	std::cout << (dynamic_cast<A*>(p) ? "A" : dynamic_cast<B*>(p) ? "B" : "C");
}

void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A";
		return; 
	}
	catch (std::exception & e){}

	try
	{
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B";
		return; 
	}
	catch (std::exception & e){}

	std::cout << "C";
	return; 
}
