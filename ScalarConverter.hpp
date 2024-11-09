/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:25:14 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/09 15:07:57 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string.h>

class ScalarConverter {
	public:
		ScalarConverter(void);
		~ScalarConverter(void);

		static void	*convert(std::string n);
};

#endif