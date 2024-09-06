/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:03:31 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 11:07:11 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>

class Contact {
	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickname,
			std::string phoneNumber, std::string darkestSecret);
		void display(int id);
		bool getIsInitalized();
	private:
		std::string firstName_;
		std::string lastName_;
		std::string nickname_;
		std::string phoneNumber_;
		std::string darkestSecret_;
		bool is_initialized_;
};

#endif
