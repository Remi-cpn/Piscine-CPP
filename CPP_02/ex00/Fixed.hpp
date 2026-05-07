/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:37:57 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/06 15:33:17 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& srcFixed);
		~Fixed(void);

		Fixed& 	operator=(const Fixed& srcFixed);
		
		int 	getRawBits(void) const ;
		void 	setRawBits(int const raw);

	private:
		int 				_raw;
		static const int 	_fractional;
};

#endif