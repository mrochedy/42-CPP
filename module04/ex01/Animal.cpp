/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:56 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/09 17:54:36 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	_type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Brrrrr..." << std::endl;
}

std::string Animal::getType() const {
	return (_type);
}
