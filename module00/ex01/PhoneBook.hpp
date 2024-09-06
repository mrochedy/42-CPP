/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:57:28 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/05 14:47:19 by mrochedy         ###   ########.fr       */
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
	private:
		Contact contacts_[8];
};

#endif
