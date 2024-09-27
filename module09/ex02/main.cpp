/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:30:53 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/27 15:19:10 by mrochedy         ###   ########.fr       */
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

	std::vector<int> pmV = pm.getMainV();
	std::cout << "Before:\t";
	for (std::vector<int>::const_iterator it = pmV.begin(); it < pmV.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	clock_t vStart = clock();
	pm.sortVector();
	clock_t vEnd = clock();

	pmV = pm.getMainV();
	std::cout << "After:\t";
	for (std::vector<int>::const_iterator it = pmV.begin(); it < pmV.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::list<int> pmL = pm.getMainL();
	std::cout << "Before:\t";
	for (std::list<int>::const_iterator it = pmL.begin(); it != pmL.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	clock_t lStart = clock();
	pm.sortList();
	clock_t lEnd = clock();

	pmL = pm.getMainL();
	std::cout << "After:\t";
	for (std::list<int>::const_iterator it = pmL.begin(); it != pmL.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::deque<int> pmD = pm.getMainD();
	std::cout << "Before:\t";
	for (std::deque<int>::const_iterator it = pmD.begin(); it != pmD.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	clock_t dStart = clock();
	pm.sortDeque();
	clock_t dEnd = clock();

	pmD = pm.getMainD();
	std::cout << "After:\t";
	for (std::deque<int>::const_iterator it = pmD.begin(); it != pmD.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	double vTime = double(vEnd - vStart) * 1000000.0 / CLOCKS_PER_SEC;
	double lTime = double(lEnd - lStart) * 1000000.0 / CLOCKS_PER_SEC;
	double dTime = double(dEnd - dStart) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << pmV.size() << " elements with std::vector : " << vTime << " us" << std::endl;
	std::cout << "Time to process a range of " << pmV.size() << " elements with std::list : " << lTime << " us" << std::endl;
	std::cout << "Time to process a range of " << pmD.size() << " elements with std::deque : " << dTime << " us" << std::endl;

	return 0;
}
