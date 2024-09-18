/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:27:06 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 16:28:59 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define WHITE "\033[1;97m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;38;5;214m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);

		Array &operator=(const Array &rhs);
		T &operator[](size_t index);

		~Array();

		size_t size() const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		T *_array;
		size_t _size;

};

#include "Array.tpp"
