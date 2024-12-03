/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:25:14 by rgobet            #+#    #+#             */
/*   Updated: 2024/12/03 09:15:36 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string.h>

class ScalarConverter {
	private:
		ScalarConverter(void);
	public:
		ScalarConverter(ScalarConverter const &obj);
		~ScalarConverter(void);
		ScalarConverter const &operator=(ScalarConverter const &a);

		static void	convert(std::string n);
};

#endif