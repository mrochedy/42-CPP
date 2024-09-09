/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:53:19 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/09 15:08:47 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
	_name = "default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap(" << name << ") constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	this->_name = rhs._name;
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no energy points left: cannot attack!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead: cannot attack!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is already dead: cannot take more damage!" << std::endl;
	else {
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no energy points left: cannot repair itself!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead: cannot repair itself!" << std::endl;
	else {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself and gets "
			<< amount << " hit points back!" << std::endl;
	}
}
