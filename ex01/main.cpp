/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:00:14 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/15 15:18:44 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void) {
	Data test;
	uintptr_t	verif;

	test.content = 8;
	verif = Serializer::serialize(&test);
	std::cout << "Serialize (Data -> uintptr_t): " << verif << std::endl;
	std::cout << "Deserialize (uintptr_t -> Data): " << Serializer::deserialize(verif) << std::endl;
	return (0);
}