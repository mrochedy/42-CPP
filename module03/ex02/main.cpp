/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:23:07 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/09 11:34:56 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap fragtrap1("Maxime");
	FragTrap defaultFragtrap;
	FragTrap fragtrap2("Manon");

	fragtrap1.attack("Non-existent FragTrap");
	fragtrap2.takeDamage(100);
	fragtrap2.attack("Non-existent FragTrap");
	fragtrap2.beRepaired(1);
	fragtrap2.attack("Non-existent FragTrap");
	fragtrap2.takeDamage(10);
	fragtrap1.attack("Non-existent FragTrap");
	fragtrap1.highFivesGuys();
	return 0;
}
