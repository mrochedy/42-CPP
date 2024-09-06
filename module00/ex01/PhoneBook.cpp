/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:27:50 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/05 22:15:24 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

void PhoneBook::addContact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber, std::string darkestSecret) {
	for (int i = 7; i >= 1; i--)
		PhoneBook::contacts_[i] = PhoneBook::contacts_[i - 1];
	PhoneBook::contacts_[0] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

void PhoneBook::displayContact(int id) {
	if (PhoneBook::contacts_[id].getIsInitalized())
		PhoneBook::contacts_[id].display(id);
	else
		std::cout << "Contact " << id + 1 << " does not exist" << std::endl;
}
