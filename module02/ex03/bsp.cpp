/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:26:17 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/08 13:29:51 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed calculate_area(const Point a, const Point b, const Point c) {
	Fixed area = Fixed(0.5f) * (a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));

	if (area < Fixed(0))
		area = Fixed(0) - area;

	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	Fixed abcArea = calculate_area(a, b, c);
	Fixed abpArea = calculate_area(a, b, point);
	Fixed bcpArea = calculate_area(b, c, point);
	Fixed capArea = calculate_area(c, a, point);

	if (abpArea == 0 || bcpArea == 0 || capArea == 0
		|| abcArea != abpArea + bcpArea + capArea)
		return false;
	return true;
}
