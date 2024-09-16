/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:26:31 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 18:29:07 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs) {
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool stringToInt(const std::string &literal, int &num) {
	std::stringstream ss(literal);

	ss >> num;

	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

bool stringToFloat(const std::string &literal, float &num) {
	std::string tmp = literal;

	if (tmp.empty() || tmp[tmp.size() - 1] != 'f')
		return false;
	tmp.resize(tmp.size() - 1);

	std::stringstream ss(tmp);

	ss >> num;

	if (ss.fail() || !ss.eof())
		return false;

	return true;
}

void fromInt(int &int_literal, char &char_literal, float &float_literal,
	double &double_literal)
{
	char_literal = int_literal;
	float_literal = (float)int_literal;
	double_literal = (double)int_literal;
}

void ScalarConverter::convert(const std::string &literal) {
	char	char_literal;
	int		int_literal;
	float	float_literal;
	double	double_literal;

	if (stringToInt(literal, int_literal)) {
		fromInt(int_literal, char_literal, float_literal, double_literal);
		std::cout << int_literal << std::endl;
		std::cout << char_literal << std::endl;
		std::cout << float_literal << std::endl;
		std::cout << double_literal << std::endl;
	} else if (stringToFloat(literal, float_literal)) {
		std::cout << float_literal << std::endl;
	} else {
		std::cerr << "no" << std::endl;
	}
}
