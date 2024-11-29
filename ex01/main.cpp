/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:00:14 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/29 15:51:27 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void) {
	Data test;
	uintptr_t	verif;

	test.content = 8;
	// test.content = "Hello world!"; // Test if you want to try with a string
	verif = Serializer::serialize(&test);
	std::cout << "Serialize (Data -> uintptr_t): " << verif << std::endl;
	std::cout << "Deserialize (uintptr_t -> Data): " << Serializer::deserialize(verif)->content << std::endl;
	return (0);
}