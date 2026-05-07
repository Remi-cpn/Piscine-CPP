/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:38:06 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/06 15:35:05 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Fixed::Fixed(void) : _raw(0)
{
	std::cout << DIM << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& srcFixed)
{
	std::cout << DIM << "Copy constructor called" << RESET << std::endl;
	*this = srcFixed;
}

Fixed::~Fixed(void)
{
	std::cout << DIM << "Destructor called" << RESET << std::endl;
}


/* ——— Variables ———————————————————————————————————————————————————————————— */
const int Fixed::_fractional = 8;




/* ——— GETTER & SETTER —————————————————————————————————————————————————————— */
int		Fixed::getRawBits(void) const
{
	std::cout << DIM << "getRawBits member function called" << RESET << std::endl;
	return Fixed::_raw; 
}
void	Fixed::setRawBits(int const raw) { Fixed::_raw = raw; }




/* ——— Public Methods ——————————————————————————————————————————————————————— */
Fixed& Fixed::operator=(const Fixed& srcFixed)
{
	std::cout << DIM << "Copy assignment operator called" << RESET << std::endl;
	_raw = srcFixed.getRawBits();
	return *this;
}
