/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:26:25 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/08 13:11:10 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point::~Point() {}

Point Point::operator=(const Point &point) {
	return Point(point);
}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}
