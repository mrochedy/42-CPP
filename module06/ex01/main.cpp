/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:13:07 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 13:26:22 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data data;

	data.val = -567;
	data.str = "No way BRO\?\?\?!!!!";

	std::cout << WHITE << "Original object: Value: " << BLUE << data.val
		<< WHITE << ", str: " << GREEN << data.str << RESET << std::endl;

	Data *same = Serializer::deserialize(Serializer::serialize(&data));

	std::cout << WHITE << "New object: Value: " << BLUE << same->val
		<< WHITE << ", str: " << GREEN << same->str << RESET << std::endl;
}
