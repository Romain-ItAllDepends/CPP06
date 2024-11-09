/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:25:19 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/09 16:02:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter init." << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "ScalarConverter destroy." << std::endl;
}

static char	convertChar(std::string c) {
	return (c[0]);
}

static double	convertDouble(std::string d) {
	char	number[d.length() + 1];

	strcpy(number, d.c_str());
	return (atof(number));
}

static float	convertFloat(std::string f) {
	return (std::stof(f));
}

static long	convertLong(std::string l) {
	char	number[l.length() + 1];

	strcpy(number, l.c_str());
	return (atof(number));
}

static bool	isPrintable(char c) {
	if (!(c < 127 && c > 31))
		return (false);
	return (true);
}

static void	*convert(std::string n) {
	const long	verif = convertLong(n);
	if (isPrintable(convertChar(n)) == false)
		std::cout << "char: Non displayable" << std::endl;
	else if (verif < 0 || verif > 128)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << convertChar(n) << std::endl;
	if (verif < 2147483648 && -2147483649 < verif)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << verif << std::endl;
	if (__FLT_MIN__ )
}
