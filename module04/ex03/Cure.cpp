/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:39:21 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/11 11:31:37 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	_type = "cure";

	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	*this = other;

	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	(void)other;
	return *this;
}

Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	AMateria *newCure = new Cure();

	return newCure;
}
