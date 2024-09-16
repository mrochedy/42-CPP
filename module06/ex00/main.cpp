/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:47:59 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 17:51:59 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Not the right number of arguments" << RESET << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	return (0);
}
