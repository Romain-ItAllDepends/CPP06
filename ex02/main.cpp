/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:00:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/29 11:11:47 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Class A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C." << std::endl;
	else
		std::cerr << "Error!" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Class A." << std::endl;
		return ;
	}
	catch(std::exception e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class B." << std::endl;
		return ;
	}
	catch(std::exception e) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class C." << std::endl;
		return ;
	}
	catch(std::exception e) {}
}

Base *generate(void) {
	int	rng = rand() % 3;

	if (rng == 0) {
		std::cout << "A" << std::endl;
		return (new A);
	}
	else if (rng == 1) {
		std::cout << "B" << std::endl;
		return (new B);
	}
	else {
		std::cout << "C" << std::endl;
		return (new C);
	}
}

int	main(void) {
	srand (time(NULL));
	Base	*test = generate();
	// B		*test2 = NULL;
	// Base	&test1 = *test2;
	Base	&test1 = *test;

	identify(test1);
	identify(test);
	delete test;
	return (0);
}