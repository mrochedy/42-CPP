/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:09:16 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/07 19:20:46 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(10);

	std::cout << c << std::endl;
	std::cout << Fixed::min(b, c) << std::endl;
	c = c + Fixed(1);
	std::cout << c << std::endl;
	std::cout << Fixed::min(b, c) << std::endl;
	c = c - Fixed(4.75f);
	std::cout << c << std::endl;
	std::cout << c / Fixed(3) << std::endl;

	return 0;
}
