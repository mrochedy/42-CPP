/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:23:07 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/09 10:53:03 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap scavtrap1("Maxime");
	ScavTrap defaultScavtrap;
	ScavTrap scavtrap2("Manon");

	scavtrap1.attack("Non-existent ScavTrap");
	scavtrap2.takeDamage(100);
	scavtrap2.attack("Non-existent ScavTrap");
	scavtrap2.beRepaired(1);
	scavtrap2.attack("Non-existent ScavTrap");
	scavtrap2.takeDamage(10);
	scavtrap1.attack("Non-existent ScavTrap");
	scavtrap1.guardGate();
	return 0;
}
