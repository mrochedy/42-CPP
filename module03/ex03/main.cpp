/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:23:07 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/09 14:47:35 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap diamondtrap1("Maxime");
	DiamondTrap defaultDiamondtrap;
	DiamondTrap diamondtrap2("Manon");

	diamondtrap1.attack("Non-existent DiamondTrap");
	diamondtrap2.takeDamage(100);
	diamondtrap2.attack("Non-existent DiamondTrap");
	diamondtrap2.beRepaired(1);
	diamondtrap2.attack("Non-existent DiamondTrap");
	diamondtrap2.takeDamage(10);
	diamondtrap1.attack("Non-existent DiamondTrap");
	defaultDiamondtrap.attack("Non-existent DiamondTrap");
	diamondtrap1.whoAmI();
	diamondtrap2.whoAmI();
	return 0;
}
