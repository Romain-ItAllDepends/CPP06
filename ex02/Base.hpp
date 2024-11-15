/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:00:50 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/15 16:10:54 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public:
		virtual ~Base(void);

		void identify(Base* p);
		void identify(Base& p);
		Base *generate(void);
};

#endif