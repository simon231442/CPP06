#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	main(void)
{
	Base*	object;
	std::srand(static_cast<unsigned int>(std::time(NULL))); // creates a seed with current time

	for (int i = 1; i < 4; i++)
	{
		std::cout << "----- " << "test " << i << " -----" << std::endl;
		object = generate();
		std::cout << "random type generated" << std::endl;
		std::cout << std::left;
		std::cout << std::setw(35) << "identifier ptr said :";
		identify(object);
		std::cout << std::endl;

		std::cout << std::setw(35) << "identifier by reference said :";
		identify(*object);
		std::cout << std::endl;

		delete object;
		std::cout << "\n" << std::endl;
	}

	return 0;
}


