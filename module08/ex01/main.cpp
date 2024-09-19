/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:01:08 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/19 11:47:19 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

std::multiset<int> *createBigRandomMultiset(unsigned int size) {
	std::multiset<int> *bigRandomMultiset = new std::multiset<int>();

	srand(time(0));
	for (unsigned int i = 0; i < size; i++) {
		int random = rand();

		if (random % 2)
			(*bigRandomMultiset).insert(random);
		else
			(*bigRandomMultiset).insert(-random);
	}

	return bigRandomMultiset;
}

int main()
{
	Span sp1 = Span(5);

	try {
		sp1.shortestSpan();
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	sp1.addNumber(6);

	try {
		sp1.longestSpan();
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	try {
		sp1.addNumber(1);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << sp1.shortestSpan() << RESET << std::endl;
	std::cout << BLUE << sp1.longestSpan() << RESET << std::endl;

	Span sp2 = Span(100000);
	std::multiset<int> *bigRandomMultiset = createBigRandomMultiset(100000);

	try {
		sp2.addNumbersRange((*bigRandomMultiset).begin(), (*bigRandomMultiset).end());
		std::cout << CYAN << sp2.shortestSpan() << RESET << std::endl;
		std::cout << BLUE << sp2.longestSpan() << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try {
		sp2.addNumber(1);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	delete bigRandomMultiset;

	return 0;
}
