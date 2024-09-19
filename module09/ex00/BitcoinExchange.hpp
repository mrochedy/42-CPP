/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:08:37 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/19 17:58:42 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <cctype>

#define WHITE "\033[1;97m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;38;5;214m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);

		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		~BitcoinExchange();

		double getDatePrice(const std::string &date) ;

		class CouldNotOpenFileException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		std::map<std::string, double> _prices;

};
