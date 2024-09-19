/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:08:33 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/19 18:22:23 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string &str) {
	std::string::size_type start = str.find_first_not_of(" ");

	if (start == std::string::npos)
		return "";

	std::string::size_type end = str.find_last_not_of(" ");

	return str.substr(start, end - start + 1);
}

bool isPositiveInt(const std::string &str) {
	size_t str_len = str.length();

	for (size_t i = 0; i < str_len; i++)
		if (!std::isdigit(str[i]))
			return false;

	return true;
}

bool isDouble(const std::string &str) {
	size_t str_len = str.length();
	size_t points_amount = 0;
	size_t i = 0;

	if (str[0] == '-')
		i++;
	for (; i < str_len; i++) {
		if (!std::isdigit(str[i]) && str[i] != '.')
			return false;
		if (str[i] == '.')
			points_amount++;
	}

	if (points_amount > 1)
		return false;

	return true;
}

bool isValidDate(const std::string &year, const std::string &month, const std::string &day) {
	if (year.length() != 4 || !isPositiveInt(year)
		|| month.length() != 2 || !isPositiveInt(month)
		|| day.length() != 2 || !isPositiveInt(day))
		return false;

	int iYear = std::atoi(year.c_str());
	int iMonth = std::atoi(month.c_str());
	int iDay = std::atoi(day.c_str());

	if (iYear < 2009 || iYear > 2024 || iMonth > 12 || iDay > 31)
		return false;

	return true;
}

void calculatePrice(BitcoinExchange &btcEx, std::string line) {
	std::stringstream ss(line);
	std::string date;
	std::string value;

	if (std::getline(ss, date, '|')) {
		if (std::getline(ss, value)) {
			date = trim(date);
			value = trim(value);
			std::stringstream ss2(date);
			std::string year;
			std::string month;
			std::string day;

			if (std::getline(ss2, year, '-') && std::getline(ss2, month, '-')
				&& std::getline(ss2, day, '|') && isValidDate(year, month, day))
			{
				if (isDouble(value)) {
					double dValue = std::atof(value.c_str());

					if (dValue >= 0) {
						if (dValue <= 1000) {
							double price = btcEx.getDatePrice(date) * dValue;
							std::cout << CYAN << date << " => " << value << " = " << price << RESET << std::endl;
						} else
							std::cerr << RED << "Error: too large a number." << RESET << std::endl;
					} else
						std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
				} else
					std::cerr << RED << "Error: not a valid value." << RESET << std::endl;
			} else
				std::cerr << RED << "Error: not a valid date." << RESET << std::endl;
		} else
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
	} else
		std::cerr << RED << "Error: Empty line." << RESET << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}

	BitcoinExchange *btcEx;
	try {
		btcEx = new BitcoinExchange();
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		file.close();
		return 1;
	}

	std::string line;
	while (std::getline(file, line))
		calculatePrice(*btcEx, line);

	file.close();
	delete btcEx;

	return 0;
}
