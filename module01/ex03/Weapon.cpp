/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:56:35 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/11 13:54:00 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type) {
	_type = type;
}

const std::string &Weapon::getType() const {
	return _type;
}

void Weapon::setType(const std::string type) {
	_type = type;
}
