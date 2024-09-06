/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:40:32 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 11:09:12 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream>

int main() {
	std::string input;
	PhoneBook phoneBook;

	phoneBook.addContact("Maxime", "Rochedy", "mrochedy", "0606060606", "He's so funny");
	phoneBook.addContact("Hélios", "Daher", "hdaher", "0606060606", "He's so smart");
	phoneBook.addContact("Simon", "Abras", "sabras", "0606060606", "He's so curious");
	phoneBook.addContact("Miguel", "Simao", "msimao", "0606060606", "He's so handsome");
	phoneBook.addContact("Alexandre", "Larose", "alarose", "0606060606", "He's so mature");
	phoneBook.addContact("Jean-Baptiste", "Renier", "jrenier", "0606060606", "He's so cultivated");
	do {
		std::cout << "What do you want to do? (ADD, SEARCH or EXIT) ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;
			std::string darkestSecret;

			std::cout << "What is the first name of your contact? ";
			std::getline(std::cin, firstName);
			std::cout << "What is the last name of your contact? ";
			std::getline(std::cin, lastName);
			std::cout << "What is the nickname of your contact? ";
			std::getline(std::cin, nickname);
			std::cout << "What is the phone number of your contact? ";
			std::getline(std::cin, phoneNumber);
			std::cout << "What is the darkest secret of your contact? ";
			std::getline(std::cin, darkestSecret);

			phoneBook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
		} else if (input == "SEARCH") {
			std::string str_id;
			int id = 0;

			do {
				std::cout << "What is the ID of the contact you're looking for? (STOP to stop) ";
				std::getline(std::cin, str_id);
				std::stringstream ss(str_id);

				ss >> id;
				if (str_id != "STOP" && ss.fail())
					std::cout << "Invalid ID" << std::endl;
				else if (str_id != "STOP" && id >= 1 && id <= 8)
					phoneBook.displayContact(id - 1);
				else if (str_id != "STOP")
					std::cout << "Contact " << id << " does not exist" << std::endl;
			} while (str_id != "STOP");
		}
	} while (input != "EXIT");

	return (0);
}
