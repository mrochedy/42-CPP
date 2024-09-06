/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:47:17 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 11:07:02 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string adjustString(const std::string &str, std::size_t size) {
    if (str.size() < size)
        return std::string(size - str.size(), ' ') + str;
    else if (str.size() > size)
        return str.substr(0, size - 1) + ".";
    return str;
}

void Contact::display(int id) {
	std::stringstream ss;

	ss << id + 1;
	std::cout << adjustString(ss.str(), 10) << '|'
		<< adjustString(Contact::firstName_, 10) << '|'
		<< adjustString(Contact::lastName_, 10) << '|'
		<< adjustString(Contact::nickname_, 10) << std::endl;
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
