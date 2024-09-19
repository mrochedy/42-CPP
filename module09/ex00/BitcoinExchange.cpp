/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:08:35 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/19 17:59:59 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw CouldNotOpenFileException();

	std::string line;

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string key;
		std::string value;

		if (std::getline(ss, key, ',')) {
			if (std::getline(ss, value)) {
				double dValue = std::atof(value.c_str());
				_prices[key] = dValue;
			}
		}
	}

	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		_prices = rhs._prices;
	}

	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getDatePrice(const std::string &date) {
	std::map<std::string, double>::iterator lower = _prices.lower_bound(date);

	if (lower != _prices.begin() && (lower == _prices.end() || lower->first != date))
		lower--;

	return lower->second;
}

const char *BitcoinExchange::CouldNotOpenFileException::what() const throw() {
	return "could not open file.";
}
