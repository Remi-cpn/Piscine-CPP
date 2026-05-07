/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:38:06 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/06 15:57:26 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ——— Variables ———————————————————————————————————————————————————————————— */
const int Fixed::_fractional = 8;




/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Fixed::Fixed(void) : _raw(0){
	std::cout << DIM << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& srcFixed){
	std::cout << DIM << "Copy constructor called" << RESET << std::endl;
	*this = srcFixed;
}

Fixed::Fixed(const int i) : _raw(i){
	std::cout << DIM << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float f){
	std::cout << DIM << "Float constructor called" << RESET << std::endl;
	_raw = roundf(f * _fractional * 10);
}

Fixed::~Fixed(void){
	std::cout << DIM << "Destructor called" << RESET << std::endl;
}




/* ——— Getters & Setters ———————————————————————————————————————————————————— */
int		Fixed::getRawBits(void) const {
	std::cout << DIM << "getRawBits member function called" << RESET << std::endl;
	return Fixed::_raw; 
}

void	Fixed::setRawBits(int const raw) { Fixed::_raw = raw; }




/* ——— Methodes ————————————————————————————————————————————————————————————— */
float 	Fixed::toFloat(void) const{

}

int		Fixed::toInt(void) const {
	
}



/* ——— Operator overload ———————————————————————————————————————————————————— */
Fixed& Fixed::operator=(const Fixed& srcFixed){
	std::cout << DIM << "Copy assignment operator called" << RESET << std::endl;
	_raw = srcFixed.getRawBits();
	return *this;
}

