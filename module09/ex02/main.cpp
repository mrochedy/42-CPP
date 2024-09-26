/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:30:53 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/26 17:09:44 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe pm;

	for (int i = 1; i < argc; i++) {
		try {
			pm.addInteger(argv[i]);
		} catch (std::exception &_) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}

	const std::vector<int> pmV = pm.getV();
	std::cout << "Before:\t";
	for (std::vector<int>::const_iterator it = pmV.begin(); it < pmV.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	pm.sort();

	return 0;
}
