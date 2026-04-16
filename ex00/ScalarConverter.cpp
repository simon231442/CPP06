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
#include <cmath>

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
static void			float_double_displayable_only(double d);
static double		literal_to_double(std::string const & literal);
static void			char_handle(double d);
static void			int_handle(double d);
static bool			literal_to_char(std::string const& literal, char& c);

void				ScalarConverter::convert(std::string const& literal)
{
	float	f;
	double	d;
	char	c;

	t_displayValues	values;
	

	std::cout /*<< std::setprecision(6)*/ << std::fixed;
	// Added: handle char inputs first (single non-digit char and quoted char literal like 'a').
	if (literal_to_char(literal, c))
	{
		d = static_cast<double>(c);
		char_handle(d);
		int_handle(d);
		std::cout << std::setw(9) << std::left << "float:" << static_cast<float>(d) << "f" << std::endl;
		std::cout << std::setw(9) << std::left << "double:" << d << std::endl;
		std::cout << std::endl;
		return;
	}
	if (literal == "nan" || literal == "nanf")
		return nan_nanf_handle(values);
	if (literal == "+inf" || literal == "+inff")
		return inf_inff_handle(values);
	try
	{
		d = literal_to_double(literal);
		char_handle(d);
		try
		{
			int_handle(d);
		}
		catch (std::exception & e)
		{
			float_double_displayable_only(d);
			return;
		}
	}
	catch (std::exception & e)
	{
		all_impossible_display(values);
		return;
	}
	
	// Print float and double when everything is ok
	f = static_cast<float>(d);
	std::cout << std::setw(9) << std::left << "float:";
	if (std::isinf(f))
		std::cout << f << "f" << std::endl;
	else
		std::cout << "impossible" << "f" << std::endl;
	std::cout << std::setw(9) << std::left << "double:" << d << std::endl;
	std::cout << std::endl;
}

// Added helper: detects char literals accepted by ex00 before numeric parsing.
static bool			literal_to_char(std::string const& literal, char& c)
{
	if (literal.length() == 1)
	{
		if (!std::isdigit(static_cast<unsigned char>(literal[0])))
		{
			c = literal[0];
			return true;
		}
	}
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		c = literal[1];
		return true;
	}
	return false;
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

static void			float_double_displayable_only(double d)
{
	// Updated: do not print char again here to avoid duplicate "char:" lines.
	std::cout << std::setw(9) << std::left << "int:" << "impossible" << std::endl;
	std::cout << std::setw(9) << std::left << "float:" << static_cast<float>(d) << "f" << std::endl;
	std::cout << std::setw(9) << std::left << "double:" << d << std::endl;
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


double				literal_to_double(std::string const & literal)
{
	double	d;
	char*	endptr;

	errno = 0;

	d = std::strtod(literal.c_str(), &endptr);
	
	if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0'))
		throw std::invalid_argument("impossible");
		
	if (errno == ERANGE)
		throw std::out_of_range("impossible");
	return d;
}

static void			char_handle(double d)
{
	if (d >= 0 && d <= 127)
	{
		if (std::isprint(static_cast<int>(d)))
			std::cout << std::setw(9) << std::left << "char:" << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << std::setw(9) << std::left << "char:" << "Non displayable" << std::endl;
	}
	else
		std::cout << std::setw(9) << std::left << "char:" << "impossible" << std::endl;
}

static void			int_handle(double d)
{
	if (d < INT_MIN || d > INT_MAX)
		throw std::out_of_range("impossible");
	std::cout << std::setw(9) << std::left << "int:" << static_cast<int>(d) << std::endl;
}

