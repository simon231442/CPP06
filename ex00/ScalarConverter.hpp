#ifndef SCALARCONVERTER_hpp
# define SCALARCONVERTER_hpp

# include <string>

class ScalarConverter {
	private :
		ScalarConverter();
		ScalarConverter(ScalarConverter const& src);
		~ScalarConverter();

		ScalarConverter&	operator=(ScalarConverter const& src);
	
	public :
		static void			convert(std::string const& literal);
		};

typedef struct s_displayValues
{
	std::string		c;
	std::string		i;
	std::string		f;
	std::string		d;
}	t_displayValues;


#endif
