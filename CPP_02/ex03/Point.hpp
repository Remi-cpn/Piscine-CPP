/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:00:55 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/08 10:38:46 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	public:
		//Constructors & destructor
		Point(void);
		Point(float x, float y);
		Point(const Point& src);
		Point(const Fixed& x, const Fixed& y);
		~Point(void);

		//Operator overload
		Point& operator=(const Point&);
		Point	operator-(const Point& otherPoint) const;
		Fixed	operator*(const Point& otherPoint) const;

		//Getters & Setters
		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif