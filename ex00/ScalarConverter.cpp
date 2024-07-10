#include "ScalarConverter.hpp"


int convert_char(const std::string &to_print)
{
	std::cout.precision(3);
	std::cout << "char: " << to_print[0] << std::endl;
	std::cout << "int: " << static_cast<int>(to_print[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(to_print[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(to_print[0]) << std::endl;
	return (1);
}

int	convert_int(const std::string &to_print, int precision)
{
	int	a;

	a = atoi(to_print.c_str());
	if (a >= 32 && a <= 126)
		std::cout << "char: " << static_cast<char>(a) << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout.precision(precision);
	std::cout << "int: " << a << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
	return (1);
}

int	convert_float(const std::string &to_print, int precision)
{
	float	a;

	a = atof(to_print.c_str());
	if (a >= 32 && a <= 126)
		std::cout << "char: " << static_cast<char>(a) << std::endl;
	else if (precision == 0)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout.precision(precision);
	if (precision == 0)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(a) << std::endl;
	std::cout << "float: " << a << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
	return (1);
}

int	convert_double(const std::string &to_print, int precision)
{
	double	a;

	a = atof(to_print.c_str());
	if (a >= 32 && a <= 126)
		std::cout << "char: " << static_cast<char>(a) << std::endl;
	else if (precision == 0)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout.precision(precision);
	if (precision == 0)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(a) << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << a << std::endl;
	return (1);
}

static int check_inf(const std::string &to_print, int *i)
{
	if (to_print.substr(*i, 3) != "inf" && to_print.substr(*i, 3) != "nan")
		return (0);
	if (to_print[*i + 3] == 'f')
		return (convert_float(to_print, 0));
	return (convert_double(to_print, 0));
}

int	ScalarConverter::convert(const std::string &to_print)
{
	int	i;

	i = 0;
	if (to_print[0] == '-')
		i++;
	if (check_inf(to_print, &i))
		return (1);
	if (to_print[i] < '0' || to_print[i] > '9')
		return (convert_char(to_print));
	while (to_print[i] >= '0' && to_print[i] <= '9')
		i++;
	if (to_print[i] != '.')
		return (convert_int(to_print, i));
	i++;
	while (to_print[i] >= '0' && to_print[i] <= '9')
		i++;
	if (to_print[i] != 'f')
		return (convert_double(to_print, i));
	else
		return (convert_float(to_print, i));
}