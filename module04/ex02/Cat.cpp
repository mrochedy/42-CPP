/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:51:53 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/10 10:50:12 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	_type = "Cat";
	_brain = new Brain();

	std::cout << "Cat constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
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

Cat::Cat(const Cat &other) : AAnimal(other) {
	this->_brain = NULL;
	*this = other;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete(_brain);

	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
