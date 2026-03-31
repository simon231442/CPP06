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

#endif
