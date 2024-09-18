/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:22:24 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 17:54:20 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	std::vector<int> my_vector;
	my_vector.push_back(1);
	my_vector.push_back(2);
	my_vector.push_back(3);

	try {
		std::cout << CYAN << *easyfind(my_vector, 3) << RESET << std::endl;
		std::cout << CYAN << *easyfind(my_vector, 7) << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::list<int> my_list;
	my_list.push_back(4);
	my_list.push_back(5);
	my_list.push_back(6);

	try {
		std::cout << CYAN << *easyfind(my_list, 5) << RESET << std::endl;
		std::cout << CYAN << *easyfind(my_list, 7) << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::deque<int> my_deque;
	my_deque.push_back(7);
	my_deque.push_back(8);
	my_deque.push_back(9);

	try {
		std::cout << CYAN << *easyfind(my_deque, 7) << RESET << std::endl;
		std::cout << CYAN << *easyfind(my_deque, 4) << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}
