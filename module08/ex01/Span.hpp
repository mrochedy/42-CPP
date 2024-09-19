/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:01:23 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/19 11:16:49 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>

#define WHITE "\033[1;97m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;38;5;214m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);

		Span &operator=(const Span &rhs);

		~Span();

		void addNumber(int nb);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void addNumbersRange(std::multiset<int>::iterator begin, std::multiset<int>::iterator end);

		class TooManyElementsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughElementsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		unsigned int _maxLen;
		std::multiset<int> _store;
};
