/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:27:29 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/20 11:53:20 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

#define WHITE "\033[1;97m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;38;5;214m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class RPN {
	public:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &other);

		RPN &operator=(const RPN &rhs);

		~RPN();

		double calculate();

	private:
		std::string _expression;
};
