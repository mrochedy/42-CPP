/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:06:08 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/07 11:51:42 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("Test");
	harl.complain("ERROR");
	return 0;
}
