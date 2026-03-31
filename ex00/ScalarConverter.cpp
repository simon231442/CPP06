#include "ScalarConverter.hpp"
#include <ostream>
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const& src)
{
	(void)src;
}

ScalarConverter::ScalarConverter::~ScalarConverter()
{
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& src)
{
	(void)src;
	return *this;
}

static void			char_literal_display(std::string const& literal);

static void			convert(std::string const& literal)
{
	if (literal.length == 1 && std::isdigit(literal))
		return (char_literal_display(literal));
}

static void			char_literal_display(std::string const& literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	c = literal[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);

	std::cout << std::setw(9) << std::left << "char:" << c << std::endl;
	std::cout << std::setw(9) << std::left << "float:" << f << std::endl;
}



