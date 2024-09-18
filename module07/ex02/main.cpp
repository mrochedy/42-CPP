/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:26:56 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 16:45:22 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
	Array<int> arr1;
	try {
		arr1[0] = 1;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	Array<int> arr2(5);
	for (int i = 0; i < 5; i++)
		std::cout << WHITE << arr2[i] << RESET << std::endl;
	for (int i = 0; i < 5; i++) {
		arr2[i] = i + 1;
		std::cout << WHITE << arr2[i] << RESET << std::endl;
	}
	try {
		std::cout << arr2[5] << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	Array<std::string> arr3(3);
	arr3[0] = "Hello";
	arr3[1] = "World";
	arr3[2] = "!";

	Array<std::string> cpy(arr3);
	cpy[0] = "I";
	cpy[1] = "don't";
	cpy[2] = "agree";

	for (int i = 0; i < 3; i++)
		std::cout << WHITE << arr3[i] << RESET << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << WHITE << cpy[i] << RESET << std::endl;

	return 0;
}
