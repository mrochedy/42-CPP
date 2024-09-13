/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:47 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/13 14:03:22 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter() {
	_name = "default";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;

	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : ICharacter() {
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;

	// std::cout << "Character( " << name << " ) constructor called" << std::endl;
}

Character::Character(const Character &other) : ICharacter(other) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = other;

	// std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];

	// std::cout << "Character destructor called" << std::endl;
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		this->_name = other._name;

		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];

			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}

	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	int i = 0;

	for (; i < 4; i++)
		if (_inventory[i] == NULL)
			break ;
	if (i < 4)
		_inventory[i] = m;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx] = NULL;
		return ;
	}
}

AMateria *Character::getMateriaAddr(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx])
		return _inventory[idx];
	return NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}
