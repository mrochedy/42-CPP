/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:05:12 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/12 11:06:47 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void Fixed::setRawBits( int const raw ) {
	_rawVal = raw;
}

int Fixed::getRawBits() const {
	return (_rawVal);
}

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_rawVal = 0;
}

Fixed::Fixed(const int nb) {
	std::cout << "Int constructor called" << std::endl;
	_rawVal = nb << _nbFractBits;
}

Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;
	_rawVal = roundf(nb * (1 << _nbFractBits));
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawVal = fixed.getRawBits();

	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt( void ) const {
	return _rawVal >> _nbFractBits;
}

float Fixed::toFloat( void ) const {
	return (float)(_rawVal / (float)(1 << _nbFractBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
