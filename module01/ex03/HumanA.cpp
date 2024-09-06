/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:11:22 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 16:30:31 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
	_name = name;
	_weapon = &weapon;
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
