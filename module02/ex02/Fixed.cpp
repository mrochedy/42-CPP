/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:05:12 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/12 11:11:19 by mrochedy         ###   ########.fr       */
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
	_rawVal = 0;
}

Fixed::Fixed(const int nb) {
	_rawVal = nb << _nbFractBits;
}

Fixed::Fixed(const float nb) {
	_rawVal = roundf(nb * (1 << _nbFractBits));
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->_rawVal = fixed.getRawBits();

	return *this;
}

Fixed Fixed::operator+(const Fixed &fixed) {
	Fixed newFixed;
	newFixed.setRawBits(this->_rawVal + fixed.getRawBits());
	return newFixed;
}

Fixed Fixed::operator-(const Fixed &fixed) {
	Fixed newFixed;
	newFixed.setRawBits(this->_rawVal - fixed.getRawBits());
	return newFixed;
}

Fixed Fixed::operator*(const Fixed &fixed) {
	Fixed newFixed;
	newFixed.setRawBits((this->_rawVal * fixed.getRawBits()) >> _nbFractBits);
	return newFixed;
}

Fixed Fixed::operator/(const Fixed &fixed) {
	if (fixed.getRawBits() == 0)
	{
		std::cerr << "Error: Division by 0" << std::endl;
		return *this;
	}
	Fixed newFixed;
	newFixed.setRawBits((this->_rawVal << _nbFractBits) / fixed.getRawBits());
	return newFixed;
}

Fixed &Fixed::operator++() {
	this->_rawVal++;
	return *this;
}

Fixed &Fixed::operator--() {
	this->_rawVal--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed newFixed(*this);
	this->_rawVal++;
	return newFixed;
}

Fixed Fixed::operator--(int) {
	Fixed newFixed(*this);
	this->_rawVal--;
	return newFixed;
}

bool Fixed::operator>(const Fixed &fixed) {
	bool ret = this->_rawVal > fixed.getRawBits();
	return ret;
}

bool Fixed::operator>=(const Fixed &fixed) {
	bool ret = this->_rawVal >= fixed.getRawBits();
	return ret;
}

bool Fixed::operator<(const Fixed &fixed) {
	bool ret = this->_rawVal < fixed.getRawBits();
	return ret;
}

bool Fixed::operator<=(const Fixed &fixed) {
	bool ret = this->_rawVal <= fixed.getRawBits();
	return ret;
}

bool Fixed::operator==(const Fixed &fixed) {
	bool ret = this->_rawVal == fixed.getRawBits();
	return ret;
}

bool Fixed::operator!=(const Fixed &fixed) {
	bool ret = this->_rawVal != fixed.getRawBits();
	return ret;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return (a);
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return (a);
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return b;
}

Fixed::~Fixed() {}

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
