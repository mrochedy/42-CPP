/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:20:21 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/09 10:51:01 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = scavtrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
	this->_name = scavtrap._name;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints <= 0)
		std::cout << "ScavTrap " << _name << " has no energy points left: cannot attack!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " is dead: cannot attack!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
