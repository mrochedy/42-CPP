/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:18:53 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/05 14:07:44 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		std::string	str(argv[i]);
		for (std::string::iterator it = str.begin(); it != str.end(); it++)
			*it = std::toupper(*it);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
