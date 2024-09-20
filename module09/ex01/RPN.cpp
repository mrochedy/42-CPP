/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:20:25 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/20 12:19:08 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _expression("") {}

RPN::RPN(std::string expression) : _expression(expression) {}

RPN::RPN(const RPN &other) : _expression(other._expression) {}

RPN &RPN::operator=(const RPN &rhs) {
	(void)rhs;

	return *this;
}

RPN::~RPN() {}

bool isValidOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

double RPN::calculate() {
	size_t i = 0;
	size_t str_len = _expression.length();
	std::stack<double> operations;

	while (i < str_len && _expression[i] == ' ')
		i++;
	if (i == str_len)
		throw std::exception();
	for (; i < str_len; i++) {
		if (!std::isdigit(_expression[i]) && !isValidOperator(_expression[i]))
			throw std::exception();
		if (isValidOperator(_expression[i])) {
			if (operations.size() < 2)
				throw std::exception();

			double b = operations.top();
			operations.pop();

			double a = operations.top();
			operations.pop();

			double nb;
			if (_expression[i] == '+')
				nb = a + b;
			else if (_expression[i] == '-')
				nb = a - b;
			else if (_expression[i] == '*')
				nb = a * b;
			else
				nb = a / b;

			operations.push(nb);
		} else
			operations.push(_expression[i] - '0');

		if (i + 1 == str_len) {
			if (operations.size() == 1)
				return (operations.top());
			else
				throw std::exception();
		}

		if (_expression[++i] != ' ')
			throw std::exception();
	}
	return 0;
}
