/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:27:10 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/10 10:51:15 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	_type = "Dog";
	_brain = new Brain();

	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	this->_brain = NULL;
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);

		if (this->_brain)
			delete this->_brain;

		this->_type = rhs._type;

		if (rhs._brain)
			this->_brain = new Brain(*rhs._brain);
		else
			this->_brain = NULL;
	}
	return *this;
}

Dog::~Dog() {
	delete(_brain);

	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
