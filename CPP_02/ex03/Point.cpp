/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:00:47 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/08 11:04:03 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Point::Point(void): _x(0), _y (0) {}
Point::Point(float x, float y): _x(x), _y(y) {}
Point::Point(const Point& src): _x(src.getX()), _y(src.getY()){}
Point::Point(const Fixed& x, const Fixed& y): _x(x), _y(y) {}
Point::~Point(void){}


/* ——— Getters & Setters ———————————————————————————————————————————————————— */
Fixed Point::getX(void) const{ return Point::_x; }
Fixed Point::getY(void) const{ return Point::_y; }


/* ——— Operator overload ———————————————————————————————————————————————————— */
Point& Point::operator=(const Point&){ return *this; }
Point	Point::operator-(const Point& otherPoint) const { return Point (this->_x - otherPoint.getX(), this->_y - otherPoint.getY()); }
Fixed	Point::operator*(const Point& otherPoint) const { return Fixed (this->_x * otherPoint.getY() - this->_y * otherPoint.getX()); }