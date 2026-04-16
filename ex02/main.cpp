#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iomanip>

int	main(void)
{
	base*	object;
	std::srand();

	for (int i = 1; i < 4; i++)
	{
		std::cout << "----- " << "test " << i << " -----" << std::endl;
		object = generate();
		std::cout << "random type genereted" << std::endl;
		std::cout << std::setw(20) << "identificator ptr saied :" << identify(object) << std::endl;
		std::cout << std::setw(20) << "identificator by reference saied :" << identify(object) << std::endl;

		delete object;
		std::cout << "\n" << std::endl;
	}

	return 0;
}


