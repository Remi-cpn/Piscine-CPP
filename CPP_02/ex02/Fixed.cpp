/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:38:06 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/08 11:13:46 by rcompain         ###   ########.fr       */
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

Fixed::Fixed(const int i) : _raw(i << _fractional){
	std::cout << DIM << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float f): _raw(roundf(f * (1 << _fractional))){
	std::cout << DIM << "Float constructor called" << RESET << std::endl;
}

Fixed::~Fixed(void){
	std::cout << DIM << "Destructor called" << RESET << std::endl;
}


/* ——— Getters & Setters ———————————————————————————————————————————————————— */
int		Fixed::getRawBits(void) const { return Fixed::_raw; }
void	Fixed::setRawBits(int const raw) { Fixed::_raw = raw; }


/* ——— Methodes ————————————————————————————————————————————————————————————— */
float 	Fixed::toFloat(void) const{ return _raw / (float)(1 << _fractional); }
int		Fixed::toInt(void) const { return _raw >> _fractional; }


/* ——— Static functions ————————————————————————————————————————————————————— */
Fixed& 			Fixed::max(Fixed& fixed1, Fixed& fixed2){ return fixed1 > fixed2 ? fixed1 : fixed2; }
const Fixed& 	Fixed::max(const Fixed& fixed1, const Fixed& fixed2){ return fixed1 > fixed2 ? fixed1 : fixed2; }
Fixed& 			Fixed::min(Fixed& fixed1, Fixed& fixed2){ return fixed1 < fixed2 ? fixed1 : fixed2; }
const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2){ return fixed1 < fixed2 ? fixed1 : fixed2; }


/* ——— Operator overload ———————————————————————————————————————————————————— */
std::ostream& operator<<(std::ostream& os, const Fixed& srcFixed){ return os << srcFixed.toFloat(); }
bool	Fixed::operator>(const Fixed& otherFixed) const { return this->_raw > otherFixed.getRawBits(); }
bool	Fixed::operator<(const Fixed& otherFixed) const { return this->_raw < otherFixed.getRawBits(); }
bool	Fixed::operator>=(const Fixed& otherFixed) const { return this->_raw >= otherFixed.getRawBits(); }
bool	Fixed::operator<=(const Fixed& otherFixed) const { return this->_raw <= otherFixed.getRawBits(); }
bool	Fixed::operator==(const Fixed& otherFixed) const { return this->_raw == otherFixed.getRawBits(); }
bool	Fixed::operator!=(const Fixed& otherFixed) const { return this->_raw != otherFixed.getRawBits(); }
Fixed	Fixed::operator+(const Fixed& otherFixed) const { return Fixed (this->toFloat() + otherFixed.toFloat()); }
Fixed	Fixed::operator-(const Fixed& otherFixed) const { return Fixed (this->toFloat() - otherFixed.toFloat()); }
Fixed	Fixed::operator*(const Fixed& otherFixed) const { return Fixed (this->toFloat() * otherFixed.toFloat()); }
Fixed	Fixed::operator/(const Fixed& otherFixed) const { return Fixed (this->toFloat() / otherFixed.toFloat()); }

Fixed& 	Fixed::operator=(const Fixed& srcFixed){
	_raw = srcFixed.getRawBits();
	return *this;
}

Fixed&	Fixed::operator++(void){
	_raw++;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed save = *this;
	_raw++;
	return save;
}

Fixed&	Fixed::operator--(void){
	_raw--;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed save = *this;
	_raw--;
	return save;
}

