/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:23:07 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/08 15:32:26 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap1("Maxime");
	ClapTrap defaultClaptrap;
	ClapTrap claptrap2("Manon");

	claptrap1.attack("Non-existent ClapTrap");
	claptrap2.takeDamage(10);
	claptrap2.attack("Non-existent ClapTrap");
	claptrap2.beRepaired(1);
	claptrap2.attack("Non-existent ClapTrap");
	claptrap2.takeDamage(10);
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	claptrap1.attack("Non-existent ClapTrap");
	return 0;
}
