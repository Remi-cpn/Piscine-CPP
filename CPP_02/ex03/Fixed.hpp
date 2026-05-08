/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:37:57 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/08 11:15:09 by rcompain         ###   ########.fr       */
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
		bool	operator>(const Fixed& otherFixed) const;
		bool	operator<(const Fixed& otherFixed) const;
		bool	operator>=(const Fixed& otherFixed) const;
		bool	operator<=(const Fixed& otherFixed) const;
		bool	operator==(const Fixed& otherFixed) const;
		bool	operator!=(const Fixed& otherFixed) const;
		Fixed	operator+(const Fixed& otherFixed) const;
		Fixed	operator-(const Fixed& otherFixed) const;
		Fixed	operator*(const Fixed& otherFixed) const;
		Fixed	operator/(const Fixed& otherFixed) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		

		//Member functions
		float 	toFloat(void) const;
		int		toInt(void) const;

		//Static functions
		static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed&		min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
		
		//Getters & Setters
		int 	getRawBits(void) const ;
		void 	setRawBits(int const raw);

	private:
		int 				_raw;
		static const int 	_fractional;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& srcFixed);

#endif