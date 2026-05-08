/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:01:19 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/08 11:00:25 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ab, bc, ca;
	//(B - A) × (P - A)  =  (Bx-Ax)*(Py-Ay) - (By-Ay)*(Px-Ax)
	ab = (b - a) * (point - a);
	bc = (c - b) * (point - b);
	ca = (a - c) * (point - c);
	return (ab > 0 && ca > 0 && bc > 0) || (ab < 0 && ca < 0 && bc < 0);
}
