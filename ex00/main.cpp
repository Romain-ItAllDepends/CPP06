/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:23:29 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/11 14:55:05 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "Error: only one argument is required." << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}