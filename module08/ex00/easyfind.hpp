/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:12:38 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/25 16:29:24 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

#define WHITE "\033[1;97m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;38;5;214m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class ValueNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Value not found");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw ValueNotFoundException();

	return it;
}
