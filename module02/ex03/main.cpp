/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:14:58 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/08 13:31:16 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point );

int main() {
	// INSIDE THE TRIANGLE
	{
		Point a(1, 1);
		Point b(4, 1);
		Point c(2.5, 4);
		Point p(2.5, 2);

		bsp(a, b, c, p) == true ? std::cout << "Point is inside the triangle" << std::endl
			: std::cout << "Point is not inside the triangle" << std::endl;
	}
	// ON THE EDGE OF THE TRIANGLE (OUTSIDE)
	{
		Point a(0, 0);
		Point b(4, 0);
		Point c(2, 3);
		Point p(2, 0);

		bsp(a, b, c, p) == true ? std::cout << "Point is inside the triangle" << std::endl
			: std::cout << "Point is not inside the triangle" << std::endl;
	}
	// ON A VERTEX OF THE TRIANGLE (OUTSIDE)
	{
		Point a(0, 0);
		Point b(5, 0);
		Point c(2, 4);
		Point p(0, 0);

		bsp(a, b, c, p) == true ? std::cout << "Point is inside the triangle" << std::endl
			: std::cout << "Point is not inside the triangle" << std::endl;
	}
	// OUTSIDE THE TRIANGLE
	{
		Point a(-1, -1);
		Point b(1, -1);
		Point c(0, 1);
		Point p(2, 2);

		bsp(a, b, c, p) == true ? std::cout << "Point is inside the triangle" << std::endl
			: std::cout << "Point is not inside the triangle" << std::endl;
	}
	return 0;
}
