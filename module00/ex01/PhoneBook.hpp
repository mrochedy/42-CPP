/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:57:28 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/11 10:22:20 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		void addContact(std::string firstName, std::string lastName,
			std::string nickname, std::string phoneNumber, std::string darkestSecret);
		void displayContact(int id);
		void displayAllContacts();
	private:
		Contact contacts_[8];
};

#endif
