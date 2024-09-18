/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:49:32 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 14:21:31 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	srand(time(0));
	int random = rand();

	if (random % 3 == 0)
		return new A();
	else if (random % 3 == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) == NULL) {
		if (dynamic_cast<B*>(p) == NULL) {
			if (dynamic_cast<C*>(p) == NULL)
				std::cerr << RED << "Type couldn't be identified" << RESET << std::endl;
			else
				std::cout << WHITE << "Identified type: " << YELLOW << "C" << RESET << std::endl;
		} else
			std::cout << WHITE << "Identified type: " << YELLOW << "B" << RESET << std::endl;
	} else
		std::cout << WHITE << "Identified type: " << YELLOW << "A" << RESET << std::endl;
}

void identify(Base& p) {
	Base tmp;

	try {
		tmp = dynamic_cast<A&>(p);
		std::cout << WHITE << "Identified type: " << YELLOW << "A" << RESET << std::endl;
	} catch (std::exception &_) {
		try {
			tmp = dynamic_cast<B&>(p);
			std::cout << WHITE << "Identified type: " << YELLOW << "B" << RESET << std::endl;
		} catch (std::exception &_) {
			try {
				tmp = dynamic_cast<C&>(p);
				std::cout << WHITE << "Identified type: " << YELLOW << "C" << RESET << std::endl;
			} catch (std::exception &_) {
				std::cerr << RED << "Type couldn't be identified" << RESET << std::endl;
			}
		}
	}
}

int main(void) {
	Base *b = generate();

	identify(b);
	identify(*b);

	delete b;
}
