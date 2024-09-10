/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:14:53 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/10 18:28:56 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	_type = "default";

	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) {
	_type = type;

	std::cout << "AMateria( " << type << " ) constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) {
	*this = other;

	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other) {
	(void)other;
	return *this;
}

std::string const & AMateria::getType() const {
	return _type;
}
