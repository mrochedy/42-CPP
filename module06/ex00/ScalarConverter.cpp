/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:26:31 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 12:07:55 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs) {
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void fromInf(bool isNegative) {
	std::cout << ORANGE << "char: impossible" << RESET << std::endl;
	std::cout << ORANGE << "int: impossible" << RESET << std::endl;
	if (isNegative) {
		std::cout << WHITE << "float: -inff" << RESET << std::endl;
		std::cout << WHITE << "double: -inf" << RESET << std::endl;
	} else {
		std::cout << WHITE << "float: inff" << RESET << std::endl;
		std::cout << WHITE << "double: inf" << RESET << std::endl;
	}
}

void fromNan() {
	std::cout << ORANGE << "char: impossible" << RESET << std::endl;
	std::cout << ORANGE << "int: impossible" << RESET << std::endl;
	std::cout << WHITE << "float: nanf" << RESET << std::endl;
	std::cout << WHITE << "double: nan" << RESET << std::endl;
}

void fromChar(const std::string &literal) {
	std::cout << WHITE << "char: " << literal[0] << RESET << std::endl;
	std::cout << WHITE << "int: " << static_cast<int>(literal[0]) << RESET << std::endl;
	std::cout << WHITE << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << 'f' << RESET << std::endl;
	std::cout << WHITE << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << RESET << std::endl;
}

void fromInt(const std::string &literal) {
	if (literal.length() > 11) {
		std::cerr << RED << "Invalid input" << RESET << std::endl;
		return ;
	}
	long lnb = atol(literal.c_str());
	if (lnb < INT_MIN || lnb > INT_MAX) {
		std::cerr << RED << "Invalid input" << RESET << std::endl;
		return ;
	}

	int nb = lnb;

	if (nb >= 32 && nb <= 126)
		std::cout << WHITE << "char: " << static_cast<char>(nb) << RESET << std::endl;
	else if (nb >= 0 && nb <= 127)
		std::cout << ORANGE << "char: Non displayable" << RESET << std::endl;
	else
		std::cout << ORANGE << "char: impossible" << RESET << std::endl;

	std::cout << WHITE << "int: " << nb << RESET << std::endl;
	std::cout << WHITE << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << 'f' << RESET << std::endl;
	std::cout << WHITE << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << RESET << std::endl;
}

void fromFloat(const std::string &literal) {
	double nb = atof(literal.c_str());

	if (nb >= 32 && nb <= 126)
		std::cout << WHITE << "char: " << static_cast<char>(nb) << RESET << std::endl;
	else if (nb >= 0 && nb <= 127)
		std::cout << ORANGE << "char: Non displayable" << RESET << std::endl;
	else
		std::cout << ORANGE << "char: impossible" << RESET << std::endl;

	if (nb >= static_cast<double>(INT_MIN) && nb <= static_cast<double>(INT_MAX))
		std::cout << WHITE << "int: " << static_cast<int>(nb) << RESET << std::endl;
	else
		std::cout << ORANGE << "int: impossible" << RESET << std::endl;

	if (nb >= -FLT_MAX && nb <= FLT_MAX)
		std::cout << WHITE << "float: " << std::fixed << std::setprecision(1) << nb << 'f' << RESET << std::endl;
	else
		std::cout << ORANGE << "float: impossible" << RESET << std::endl;

	if (nb >= -DBL_MAX && nb <= DBL_MAX)
		std::cout << WHITE << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << RESET << std::endl;
	else
		std::cout << ORANGE << "double: impossible" << RESET << std::endl;
}

void fromDouble(const std::string &literal) {
	double nb = atof(literal.c_str());

	if (nb >= 32 && nb <= 126)
		std::cout << WHITE << "char: " << static_cast<char>(nb) << RESET << std::endl;
	else if (nb >= 0 && nb <= 127)
		std::cout << ORANGE << "char: Non displayable" << RESET << std::endl;
	else
		std::cout << ORANGE << "char: impossible" << RESET << std::endl;

	if (nb >= static_cast<double>(INT_MIN) && nb <= static_cast<double>(INT_MAX))
		std::cout << WHITE << "int: " << static_cast<int>(nb) << RESET << std::endl;
	else
		std::cout << ORANGE << "int: impossible" << RESET << std::endl;

	if (nb >= -FLT_MAX && nb <= FLT_MAX)
		std::cout << WHITE << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << 'f' << RESET << std::endl;
	else
		std::cout << ORANGE << "float: impossible" << RESET << std::endl;

	if (nb >= -DBL_MAX && nb <= DBL_MAX)
		std::cout << WHITE << "double: " << std::fixed << std::setprecision(1) << nb << RESET << std::endl;
	else
		std::cout << ORANGE << "double: impossible" << RESET << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
	size_t str_len = literal.length();

	if (literal == "inff" || literal == "inf") {
		fromInf(false);
	} else if (literal == "-inff" || literal == "-inf") {
		fromInf(true);
	} else if (literal == "nan") {
		fromNan();
	} else if (str_len == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		fromChar(literal);
	} else {
		int dots_amount = 0;
		size_t i = 0;
		size_t limit = str_len;

		if (literal[str_len - 1] == 'f')
			limit = str_len - 1;
		if (literal[0] == '-')
			i++;

		for (; i < limit && (std::isdigit(literal[i]) || literal[i] == '.'); i++)
			if (literal[i] == '.')
				dots_amount++;

		if (i == limit && dots_amount == 1) {
			if (literal[str_len - 1] == 'f')
				fromFloat(literal);
			else
				fromDouble(literal);
		} else if (i == limit && dots_amount == 0) {
			fromInt(literal);
		} else
			std::cerr << RED << "Invalid input" << RESET << std::endl;
	}
}
