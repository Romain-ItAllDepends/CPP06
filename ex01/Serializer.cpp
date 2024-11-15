/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:23 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/15 14:59:58 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
}

Serializer::~Serializer(void) {
}

Serializer::Serializer(Serializer const &obj) {
	*this = obj;
}

Serializer const &Serializer::operator=(Serializer const &obj) {
	(void)obj;
	return (*this);
}

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
