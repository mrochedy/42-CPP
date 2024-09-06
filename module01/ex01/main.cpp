/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:27:16 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 15:35:49 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int N = 8;
	Zombie *horde = zombieHorde(N, "Maxime");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
