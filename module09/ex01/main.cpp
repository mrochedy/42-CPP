/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:52:32 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/20 12:19:34 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: Invalid number of arguments." << RESET << std::endl;
		return 1;
	}

	RPN rpn(argv[1]);
	double result;

	try {
		result = rpn.calculate();
	} catch (std::exception &_) {
		std::cerr << RED << "Error" << RESET << std::endl;
		return 1;
	}

	std::cout << GREEN << result << RESET << std::endl;
	return 0;
}
