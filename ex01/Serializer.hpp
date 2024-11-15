/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:24:26 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/15 15:20:59 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"
# include <stdint.h>
# include <string>

class Serializer
{
	private:
		Serializer(void);
	public:
		Serializer(Serializer const &obj);
		~Serializer(void);
		Serializer const &operator=(Serializer const &obj);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif