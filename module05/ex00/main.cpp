/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:39:14 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 11:23:53 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Maxime", 15);
		Bureaucrat b2("Helios", 112);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		b1.incrementGrade();
		b2.decrementGrade();

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		for (int i = 0; i < 14; i++)
			b1.incrementGrade();

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat b("Invalid Bureaucrat", 151);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat *b = new Bureaucrat("Miguel", 1);
	try {
		std::cout << *b << std::endl;

		b->incrementGrade();

		std::cout << *b << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	delete b;
}
