/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:29:35 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/19 14:04:27 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << YELLOW << "Top: " << mstack.top() << RESET << std::endl;

	mstack.pop();
	std::cout << GREEN << "Size after pop: " << mstack.size() << RESET << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << WHITE << "Elements in stack (forward):" << RESET << std::endl;
	++it;
	--it;
	for (; it != ite; it++)
		std::cout << CYAN << *it << RESET << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << WHITE << "Elements in stack (reverse):" << RESET << std::endl;
	for (; rit != rite; rit++)
		std::cout << CYAN << *rit << RESET << std::endl;

	std::cout << WHITE << "Modifying elements through iterator:" << RESET << std::endl;
	for (it = mstack.begin(); it != mstack.end(); it++)
		*it += 10;

	std::cout << WHITE << "Elements after modification:" << RESET << std::endl;
	for (it = mstack.begin(); it != mstack.end(); it++)
		std::cout << CYAN << *it << RESET << std::endl;

	std::cout << GREEN << "Size after modifications: " << mstack.size() << RESET << std::endl;

	MutantStack<int> s(mstack);
	std::cout << GREEN << "Copied stack size: " << s.size() << RESET << std::endl;

	std::cout << WHITE << "Elements in copied stack:" << RESET << std::endl;
	for (it = s.begin(); it != s.end(); it++)
		std::cout << CYAN << *it << RESET << std::endl;

	return 0;
}
