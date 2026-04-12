#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <climits>

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
static void			all_impossible_display(t_displayValues& values);
static void			final_display(t_displayValues& values);
static void			float_double_displayable_only(long l);
static long			literal_to_long(std::string const & literal);
static void			char_handle(long l);
static void			int_handle(long l);

void				ScalarConverter::convert(std::string const& literal)
{
	long	l;

	t_displayValues	values;
	if (literal == "nan" || literal == "nanf")
		return nan_nanf_handle(values);
	if (literal == "+inf" || literal == "+inff")
		return inf_inff_handle(values);
	try
	{
		l = literal_to_long(literal);
		char_handle(l);
		try
		{
			int_handle(l);
		}
		catch (std::exception & e)
		{
			float_double_displayable_only(l);
			return;
		}
	}
	catch (std::exception & e)
	{
		all_impossible_display(values);
		return;
	}
	
	// Print float and double when everything is ok
	std::cout << std::setw(9) << std::left << "float:" << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << std::setw(9) << std::left << "double:" << static_cast<double>(l) << ".0" << std::endl;
	std::cout << std::endl;
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

static void			all_impossible_display(t_displayValues& values)
{
	values.c = "impossible";
	values.i = "impossible";
	values.f = "impossible";
	values.d = "impossible";

	final_display(values);
}

static void			float_double_displayable_only(long l)
{
	std::cout << std::setw(9) << std::left << "char:" << "impossible" << std::endl;
	std::cout << std::setw(9) << std::left << "int:" << "impossible" << std::endl;
	std::cout << std::setw(9) << std::left << "float:" << static_cast<float>(l) << std::endl;
	std::cout << std::setw(9) << std::left << "double:" << static_cast<double>(l) << std::endl;
	std::cout << std::endl;
}


static void			final_display(t_displayValues& values)
{
	std::cout << std::setw(9) << std::left << "char:" << values.c << std::endl;
	std::cout << std::setw(9) << std::left << "int:" << values.i << std::endl;
	std::cout << std::setw(9) << std::left << "float:" << values.f << std::endl;
	std::cout << std::setw(9) << std::left << "double:" << values.d << std::endl;
	std::cout << std::endl;
}


long				literal_to_long(std::string const & literal)
{
	long	l;
	char*	endptr;

	errno = 0;

	l = std::strtol(literal.c_str(), &endptr, 10);
	if (*endptr != '\0')
		throw std::invalid_argument("impossible");
	if (errno == ERANGE)
		throw std::out_of_range("impossible");
	return l;
}

/*
static int			char_int_display(std::string const& literal)
{
	int		i;

	try
	{
		i = std::stoi(literal);
		char_handle(i);
		std::cout << std::setw(9) << std::left << "int:" << i << std::endl;
	}
	catch (std::invalid_argument const & e)
	{
		std::cout << std::setw(9) << std::left << "char:" << "impossible" << std::endl;
		std::cout << std::setw(9) << std::left << "int:" << "impossible"  << std::endl;
	}
	catch (std::out_of_range const & e)
	{
		std::cout << std::setw(9) << std::left << "char:" << "impossible" << std::endl;
		std::cout << std::setw(9) << std::left << "int:" << "impossible"  << std::endl;
	}
}
*/

static void			char_handle(long l)
{
	if (l >= 0 && l <= 127)
	{
		if (std::isprint(static_cast<int>(l)))
			std::cout << std::setw(9) << std::left << "char:" << "'" << static_cast<char>(l) << "'" << std::endl;
		else
			std::cout << std::setw(9) << std::left << "char:" << "Non displayable" << std::endl;
	}
	else
		std::cout << std::setw(9) << std::left << "char:" << "impossible" << std::endl;
}

static void			int_handle(long l)
{
	if (l < INT_MIN || l > INT_MAX)
		throw std::out_of_range("impossible");
	std::cout << std::setw(9) << std::left << "int:" << static_cast<int>(l) << std::endl;
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
