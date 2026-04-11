#include "ScalarConverter.hpp"
#include <iostream>
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

static void			nan_nanf_handle(t_displayValues& values);
static void			inf_inff_handle(t_displayValues& values);
static void			final_display(t_displayValues& values);
//static void			char_literal_display(std::string const& literal);

void				ScalarConverter::convert(std::string const& literal)
{
	t_displayValues	values;
	if (literal == "nan" || literal == "nanf")
		return nan_nanf_handle(values);
	if (literal == "+inf" || literal == "+inff")
		return inf_inff_handle(values);
}

static void			nan_nanf_handle(t_displayValues& values)
{
	values.c = "impossible";
	values.i = "impossible";
	values.f = "nanf";
	values.d = "nan";

	final_display(values);
}

static void			inf_inff_handle(t_displayValues& values)
{
	values.c = "impossible";
	values.i = "impossible";
	values.f = "+inff";
	values.d = "+inf";

	final_display(values);
}

static void			final_display(t_displayValues& values)
{
	std::cout << std::setw(9) << std::left << "char:" << values.c << std::endl;
	std::cout << std::setw(9) << std::left << "int:" << values.i << std::endl;
	std::cout << std::setw(9) << std::left << "float:" << values.f << std::endl;
	std::cout << std::setw(9) << std::left << "double:" << values.d << std::endl;
	std::cout << std::endl;
}



/*
	if (literal == "nan" || "nanf")
		return nan_nanf_handle(literal);
	if (literal.length() == 1 && std::isdigit(literal[0]))
		return char_literal_display(literal);
}

static void			nan_nanf_handle(literal)
{


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
	std::cout << std::setw(9) << std::left << "int:" << i << std::endl;
	std::cout << std::setw(9) << std::left << "float:" << f << std::endl;
	std::cout << std::setw(9) << std::left << "double:" << d << std::endl;
	std::cout << std::endl;
}

void				value_display
}
*/
