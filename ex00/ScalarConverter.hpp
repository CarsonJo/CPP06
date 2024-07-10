#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <limits>
#include <iostream>
#include <cstdlib>

class ScalarConverter
{
	public :
		static int	convert(const std::string &to_print);
	private :
		ScalarConverter();
		ScalarConverter(ScalarConverter &to_copy);
		~ScalarConverter();
		void	operator=(ScalarConverter &to_copy);
};

#endif
