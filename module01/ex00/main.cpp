/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:07:09 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 15:13:22 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *zombie1 = newZombie("Maxime");
	Zombie *zombie2 = newZombie("Helios");
	Zombie *zombie3 = newZombie("Simon");

	zombie1->announce();
	delete(zombie1);

	zombie2->announce();

	randomChump("Miguel");

	zombie3->announce();
	delete(zombie3);
	delete(zombie2);
}
