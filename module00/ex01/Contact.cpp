/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:47:17 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/11 11:09:18 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string adjustString(const std::string &str, std::size_t size) {
	if (str.size() > size)
	 return str.substr(0, size - 1) + ".";
	return str;
}

void Contact::fastDisplay(int id) {
	std::stringstream ss;

	ss << id + 1;
	std::cout << '|' << std::setw(10) << std::right << adjustString(ss.str(), 10);
	std::cout << '|' << std::setw(10) << std::right << adjustString(firstName_, 10);
	std::cout << '|' << std::setw(10) << std::right << adjustString(lastName_, 10);
	std::cout << '|' << std::setw(10) << std::right << adjustString(nickname_, 10);
	std::cout << '|' << std::endl;
}

void Contact::longDisplay() {
	std::cout << "First name: " << firstName_ << std::endl;
	std::cout << "Last name: " << lastName_ << std::endl;
	std::cout << "Nickname: " << nickname_ << std::endl;
	std::cout << "Phone number: " << phoneNumber_ << std::endl;
	std::cout << "Darkest secret: " << darkestSecret_ << std::endl;
}

Contact::Contact() {
	firstName_ = "";
	lastName_ = "";
	nickname_ = "";
	phoneNumber_ = "";
	darkestSecret_ = "";
	is_initialized_ = false;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
			std::string phoneNumber, std::string darkestSecret) {
	firstName_ = firstName;
	lastName_ = lastName;
	nickname_ = nickname;
	phoneNumber_ = phoneNumber;
	darkestSecret_ = darkestSecret;
	is_initialized_ = true;
}

bool Contact::getIsInitalized() {
	return (is_initialized_);
}
