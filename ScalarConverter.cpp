/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:25:19 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/12 15:55:52 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter init." << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "ScalarConverter destroy." << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj) {
	*this = obj;
}

ScalarConverter const & ScalarConverter::operator=(ScalarConverter const &a) {
	(void)a;
    return *this;
}

static bool	isDigit(const char *s) {
	int	i = 0;
	int	dot = 0;
	
	while (s[i]) {
		if (s[i] == '.')
			dot++;
		if (!s[i + 1] && s[i] == 'f')
			break;
		if ((s[i] < 48 || 57 < s[i]) || dot > 1) {
			if (s[i] != '.' || dot > 1)
				return (false);
		}
		i++;
	}
	return (true);
}

static char	tmp(char *s) {
	int	i = 0;
	int	tmp = 0;
	int	sign = 1;

	if (s[0] == '-')
		sign *= 1;
	while (s[i] && s[i] != '.') {
		tmp *= 10;
		tmp += s[i] - 48;
		i++;
	}
	return (tmp * sign);
}

static char	convertChar(std::string c) {
	char	x[c.length() + 1];

	strcpy(x, c.c_str());
	return (tmp(x));
}

static double	convertDouble(std::string d) {
	char	x[d.length() + 1];

	strcpy(x, d.c_str());
	return (static_cast<double>(strtold(x, NULL)));
}

static float	convertFloat(std::string f) {
	char	x[f.length() + 1];

	strcpy(x, f.c_str());
	return (static_cast<float>(strtold(x, NULL)));
}

static long	convertLong(std::string l) {
	char	x[l.length() + 1];

	strcpy(x, l.c_str());
	return (static_cast<long>(strtoll(x, NULL, 10)));
}

static bool	isPrintable(std::string str) {
	char	x[str.length() + 1];
	int	c;
	
	strcpy(x, str.c_str());
	c = atoi(x);
	if (str.length() > 1 || isDigit(x) == false)
		return (false);
	return (true);
}

static bool	isDisplayable(std::string str) {
	char	x[str.length() + 1];
	int	c;
	
	strcpy(x, str.c_str());
	c = atoi(x);
	if (!(c < 127 && c > 31))
		return (false);
	return (true);
}

void	ScalarConverter::convert(std::string n) {
	const long	verif = convertLong(n);
	char	x[n.length() + 1];
	
	strcpy(x, n.c_str());
	
	/* EXCEPTION */ /* Maybe useless */

	if (n == "nan" || n == "nanf" || n == "-inf" || n == "+inf"
		|| n == "-inff" || n == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (n == "nan" || n == "nanf")
			std::cout << "float: nanf" << std::endl;
		else
			std::cout << "float: " << n << std::endl;
		std::cout << "double: " << n << std::endl;
		return ;
	}

	/* CHAR */ /* DONE (but need to verify the convertion float to char) */

	if (verif < 0 || verif > 128 || isPrintable(n) || (isDigit(x) == 0 && n.length() > 1))
		std::cout << "char: impossible" << std::endl;
	else if (isDisplayable(n) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << convertChar(n) << "'" << std::endl;

	/* INT */ /* DONE */
	
	if (verif > 2147483647 || -2147483648 > verif || isDigit(x) == 0)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << verif << std::endl;

	/* FLOAT */

	if (isDigit(x) == 0)
		std::cout << "float: impossible" << std::endl;
	else if (verif - convertFloat(n) == 0)
		std::cout << "float: " << convertFloat(n) << ".0f" << std::endl;
	else
		std::cout << "float: " << convertFloat(n) << "f" << std::endl;
	// if (__FLT_MIN__ ) // Verif la range en entier
	// else if (n == "nan")
	// 	std::cout << "float: nanf" << std::endl;

	// /* DOUBLE */

	if (isDigit(x) == 0)
		std::cout << "double: impossible" << std::endl;
	else if (verif - convertFloat(n) == 0)
		std::cout << "double: " << convertDouble(n) << ".0" << std::endl;
	else
		std::cout << "double: " << convertDouble(n) << std::endl;
	// if (n == "nan") // Verif la range en entier
	// 	std::cout << "double: nan" << std::endl;

}
