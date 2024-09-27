/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:30:53 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/27 16:10:56 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << RED << "Error" << RESET << std::endl;
		return 1;
	}

	PmergeMe pm;

	for (int i = 1; i < argc; i++) {
		try {
			pm.addInteger(argv[i]);
		} catch (std::exception &_) {
			std::cerr << RED << "Error" << RESET << std::endl;
			return 1;
		}
	}

	std::vector<int> pmV = pm.getMainV();
	size_t size = pmV.size();

	std::cout << WHITE << "Before:\t" << BLUE;
	for (std::vector<int>::const_iterator it = pmV.begin(); it < pmV.end(); it++)
		std::cout << *it << ' ';
	std::cout << RESET << std::endl;

	clock_t vStart = clock();
	pm.sortVector();
	clock_t vEnd = clock();

	pmV = pm.getMainV();
	std::cout << WHITE << "After:\t" << BLUE;
	for (std::vector<int>::const_iterator it = pmV.begin(); it < pmV.end(); it++)
		std::cout << *it << ' ';
	std::cout << RESET << std::endl;

	clock_t dStart = clock();
	pm.sortDeque();
	clock_t dEnd = clock();

	double vTime = double(vEnd - vStart) * (double)1000000.0 / (double)CLOCKS_PER_SEC;
	double dTime = double(dEnd - dStart) * (double)1000000.0 / (double)CLOCKS_PER_SEC;

	std::cout << WHITE << "Time to process a range of " << YELLOW << size << WHITE << " elements with " << GREEN << "std::vector" << WHITE << "\t: " << CYAN << vTime << WHITE << " us" << RESET << std::endl;
	std::cout << WHITE << "Time to process a range of " << YELLOW << size << WHITE << " elements with " << GREEN << "std::deque" << WHITE << "\t: " << CYAN << dTime << WHITE << " us" << RESET << std::endl;

	return 0;
}
