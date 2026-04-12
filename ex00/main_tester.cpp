#include "ScalarConverter.hpp"
#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ifstream	file("FileTest.txt");
	std::string		arg;

	if(!file.is_open()) 
    {
        std::cout << "Error: could not open file " << std::endl;
        return (1);
    }

	while (std::getline(file, arg))
	{
		std::cout << "-------->" << arg << std::endl;
		ScalarConverter::convert(arg);
	}

	return 0;
}
