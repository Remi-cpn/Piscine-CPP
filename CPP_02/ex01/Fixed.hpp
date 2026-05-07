/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:37:57 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/06 15:54:55 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

class Fixed
{
	public:
		//Constructors & destructor
		Fixed(void);
		Fixed(const Fixed& srcFixed);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed(void);

		//Operator overload
		Fixed& 	operator=(const Fixed& srcFixed);
		Fixed&	operator<<(const Fixed& srcFixed);

		//Member functions
		float 	toFloat(void) const;
		int		toInt(void) const;
		
		//Getters & Setters
		int 	getRawBits(void) const ;
		void 	setRawBits(int const raw);

	private:
		int 				_raw;
		static const int 	_fractional;
};

#endif