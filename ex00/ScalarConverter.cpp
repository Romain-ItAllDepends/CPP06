/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:25:19 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/29 15:47:18 by rgobet           ###   ########.fr       */
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

static bool	isNotInteger(const long l, const std::string n) {
	char	str[n.length() + 1];

	strcpy(str, n.c_str());
	if (l > 2147483647 || -2147483648 > l || (l == 0 && str[0] != '0')) {
		if (n.length() > 1)
			return (true);
	}
	return (false);
}

static bool	verifyDigit(const std::string s) {
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

static bool verifyFloat(const std::string s) {
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

static bool	isDigit(const std::string s) {
	char	str[s.length() + 1];
	size_t	count = 0;
	int		x = 0;

	strcpy(str, s.c_str());
	x = std::strtold(str, NULL);
	if (verifyDigit(s) == false && s.length() > 1)
		return (false);
	if (s.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return (true);
	if (x == 0 && str[0] != '0')
		return (false);
	for (size_t i = 0 ; i < s.length() ; i++) {
		if (str[i] == '0')
			count++;
	}
	if (s.length() > 1 && x == 0 && count != s.length() && str[0] == '0')
		return (false);
	return (true);
}

static bool	noDot(std::string const n) {
	for (size_t i = 0 ; i < n.length() ; i++) {
		if (n[i] == '.')
			return (false);
	}
	return (true);
}

static bool isFloat(const std::string s) {
	char	str[s.length() + 1];
	size_t	count = 0;
	int		x = 0;

	strcpy(str, s.c_str());
	x = std::strtof(str, NULL);
	if (verifyFloat(s) && s.length() > 1)
		return (false);
	if (s.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return (true);
	if (x == 0 && str[0] != '0')
		return (false);
	for (size_t i = 0 ; i < s.length() ; i++) {
		if (str[i] == '0')
			count++;
	}
	if (s.length() > 1 && x == 0 && count != s.length())
		return (false);
	return (true);
}


static bool isDouble(const std::string s) {
	char	x[s.length() + 1];
	double	n;

	strcpy(x, s.c_str());
	n = std::strtod(x, NULL);
	if (verifyDigit(s) == false && s.length() > 1)
		return (false);
	if (s.length() == 1 && !(x[0] >= '0' && x[0] <= '9'))
		return (true);
	return (true);
}

static char	convertChar(std::string c) {
	char	x[c.length() + 1];

	strcpy(x, c.c_str());
	if (c.length() != 1)
		return (static_cast<char>(std::atoi(x)));
	return (static_cast<char>(x[0]));
}

static double	convertDouble(std::string d) {
	char	x[d.length() + 1];

	strcpy(x, d.c_str());
	if (d.length() == 1 && !(x[0] >= '0' && x[0] <= '9')) {
		return (static_cast<double>(x[0]));
	}
	return (static_cast<double>(std::strtold(x, NULL)));
}

static float	convertFloat(std::string f) {
	char	x[f.length() + 1];

	strcpy(x, f.c_str());
	if (f.length() == 1 && !(x[0] >= '0' && x[0] <= '9')) {
		return (static_cast<float>(x[0]));
	}
	return (static_cast<float>(std::strtold(x, NULL)));
}

static long	convertLong(std::string l) {
	char	x[l.length() + 1];

	strcpy(x, l.c_str());
	if (l.length() == 1 && !(x[0] >= '0' && x[0] <= '9')) {
		return (static_cast<long>(x[0]));
	}
	return (static_cast<long>(std::strtoll(x, NULL, 10)));
}

static long	convertInt(std::string i) {
	char	x[i.length() + 1];

	strcpy(x, i.c_str());
	if (i.length() == 1 && !(x[0] >= '0' && x[0] <= '9')) {
		return (static_cast<int>(x[0]));
	}
	return (static_cast<int>(std::atoi(x)));
}

static bool	isPrintable(std::string str) {
	char	x[str.length() + 1];
	int		i = 0;
	int		c = 0;
	
	strcpy(x, str.c_str());
	c = std::atoi(x);
	if ((c == 0 && x[0] == '0' && str.length() == 1) || c != 0) {
		if (c >= 0 && c < 128)
			return (true);
	}
	if (c == 0 && x[0] != '0') {
		while (x[i]) {
			if (x[i] > 127 || x[i] < 0)
				return (false);
			if (str.length() != 1 && (x[i] < '0' || x[i] > '9'))
				return (false);
			i++;
		}
		return (true);
	}
	else if (c < 0 || c > 127)
		return (false);
	return (true);
}

static bool	isDisplayable(std::string str) {
	char	x[str.length() + 1];
	int	c;
	
	strcpy(x, str.c_str());
	c = std::atoi(x);
	if (((c == 0 && x[0] == '0' && str.length() == 1)
		|| c != 0) || (str.length() == 1 && x[0] != '0')) {
		if ((c < 32 || c == 127))
			return (false);
	}
	if (c == 0 && x[0] != '0' && x[0] < 32 && x[0] >= 127 && str.length() > 1)
		return (false);
	return (true);
}

static bool	isInf(std::string n) {
	std::string	testp = "99999999999999999999999999999999999999999999999";
	std::string	testm = "-99999999999999999999999999999999999999999999999";

	if (n[0] == '-' && std::strtof(n.c_str(), NULL) != std::strtof(testm.c_str(), NULL))
		return (false);
	if (n[0] != '-' && std::strtof(n.c_str(), NULL) != std::strtof(testp.c_str(), NULL))
		return (false);
	return (true);
}

static void	infFloat(std::string n) {
	if (n[0] == '-')
		std::cout << "float: -inf" << std::endl;
	else
		std::cout << "float: +inf" << std::endl;
}

static void	infDouble(std::string n) {
	if (n[0] == '-')
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "double: +inf" << std::endl;
}

void	ScalarConverter::convert(std::string n) {
	const long	verif = convertLong(n);
	
	/* EXCEPTION */

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


	/* CHAR */ // Non displayble full bugé et caractere unique aussi et conversion int to ascii
	// Normalement good / inf print non displayble
	if (isPrintable(n) == false)
		std::cout << "char: impossible" << std::endl;
	else if (isPrintable(n) == true && isDisplayable(n) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << convertChar(n) << "'" << std::endl;

	/* INT */ // inf.0f/inf.0/nombre negatif / inf -> +inf/-inf/+inff/-inff

	if (isNotInteger(verif, n) == true || isDigit(n) == 0 || n.empty())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << convertInt(n) << std::endl;

	/* FLOAT */

	if (isDigit(n) == 0 || isFloat(n) == 0)
		std::cout << "float: impossible" << std::endl;
	else if (isInf(n) == false && isFloat(n) == true && ((n[n.length() - 3] == '.'
		&& n[n.length() - 1] == 'f' && n[n.length() - 2] == '0')
		|| (n[n.length() - 2] == '.' && n[n.length() - 1] == '0')))
		std::cout << "float: " << convertFloat(n) << ".0f" << std::endl;
	else if (isFloat(n) == true && noDot(n) == true && isInf(n) == false)
		std::cout << "float: " << convertFloat(n) << ".0f" << std::endl;
	else if (isInf(n) == false)
		std::cout << "float: " << convertFloat(n) << "f" << std::endl;
	else if (isFloat(n) == true && isInf(n) == true)
		infFloat(n);

	// /* DOUBLE */

	if (isDigit(n) == 0 || isDouble(n) == 0)
		std::cout << "double: impossible" << std::endl;
	else if (isInf(n) == false && isDouble(n) == true && ((n[n.length() - 3] == '.'
		&& n[n.length() - 1] == 'f' && n[n.length() - 2] == '0')
		|| (n[n.length() - 2] == '.' && n[n.length() - 1] == '0')))
		std::cout << "double: " << convertDouble(n) << ".0" << std::endl;
	else if (isDouble(n) == true && noDot(n) == true && isInf(n) == false)
		std::cout << "double: " << convertDouble(n) << ".0" << std::endl;
	else if (isDouble(n) == true && isInf(n) == false)
		std::cout << "double: " << convertDouble(n) << std::endl;
	else
		infDouble(n);
}
