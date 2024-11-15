/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:25:19 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/15 14:15:39 by rgobet           ###   ########.fr       */
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

static bool	isDigit(const std::string s) {
	unsigned long	i = 0;
	int	dot = 0;
	
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (i < s.length()) {
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
	if (dot > 1)
		return (false);
	return (true);
}

static bool isFloat(const std::string s) {
	unsigned long	i = 0;
	int				dot = 0;

	if (s.empty() || s[s.length() - 1] != 'f')
		return (false);
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (i < s.length() - 1) {
		if (s[i] == '.')
			dot++;
		if (dot > 1 || !isdigit(s[i]))
			return (false);
		i++;
	}
	if (dot > 1)
		return (false);
	return (true);
}

static bool isDouble(const std::string s) {
	char	*null;
	char	x[s.length() + 1];
	double	n;

	strcpy(x, s.c_str());
	n = strtod(x, &null);
	if (null[0] != 0 || null == s)
		return (false);
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

	if (verif < 0 || verif > 128 || isPrintable(n) || (isDigit(n) == 0 && n.length() > 1))
		std::cout << "char: impossible" << std::endl;
	else if (isDisplayable(n) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << convertChar(n) << "'" << std::endl;

	/* INT */ /* DONE */
	
	if (verif > 2147483647 || -2147483648 > verif || isDigit(n) == 0 || n.empty())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << verif << std::endl;

	/* FLOAT */

	if (isDigit(n) == 0 || isFloat(n))
		std::cout << "float: impossible" << std::endl;
	else if (verif - convertFloat(n) == 0)
		std::cout << "float: " << convertFloat(n) << ".0f" << std::endl;
	else
		std::cout << "float: " << convertFloat(n) << "f" << std::endl;

	// /* DOUBLE */

	if (isDigit(n) == 0 || isDouble(n) == 0)
		std::cout << "double: impossible" << std::endl;
	else if (verif - convertFloat(n) == 0)
		std::cout << "double: " << convertDouble(n) << ".0" << std::endl;
	else
		std::cout << "double: " << convertDouble(n) << std::endl;
}
