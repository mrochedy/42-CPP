/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:47 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/11 12:10:59 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter() {
	_name = "default";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 1000; i++)
		_floor[i] = NULL;

	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : ICharacter() {
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 1000; i++)
		_floor[i] = NULL;

	// std::cout << "Character( " << name << " ) constructor called" << std::endl;
}

Character::Character(const Character &other) : ICharacter(other) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 1000; i++)
		_floor[i] = NULL;
	*this = other;

	// std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0; i < 1000; i++)
		if (_floor[i])
			delete _floor[i];

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

		for (int i = 0; i < 1000; i++)
		{
			if (this->_floor[i])
				delete this->_floor[i];

			if (other._floor[i])
				this->_floor[i] = other._floor[i]->clone();
			else
				this->_floor[i] = NULL;
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
	if (idx < 4 && _inventory[idx]) {
		for (int i = 0; i < 1000; i++) {
			if (_floor[i] == NULL) {
				_floor[i] = _inventory[idx];
				break ;
			}
		}
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}
