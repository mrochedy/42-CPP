/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:29:46 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/11 11:20:53 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	_type = "ice";

	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	*this = other;

	// std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	(void)other;
	return *this;
}

Ice::~Ice() {
	// std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	AMateria *newIce = new Ice();

	return newIce;
}
