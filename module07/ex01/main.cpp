/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:11:01 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 15:21:13 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template< typename T >
void print( T& x )
{
	std::cout << x << std::endl;
	return;
}

int main() {
	int tab1[] = { 0, 1, 2, 3, 4 };
	std::string tab2[] = {"Hello", "my", "bro", "!"};

	iter( tab1, 5, print<int> );
	iter( tab2, 4, print<std::string> );

	return 0;
}
