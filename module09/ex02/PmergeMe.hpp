/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:10 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/27 16:04:23 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>
#include <deque>
#include <algorithm>

#define WHITE "\033[1;97m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;38;5;214m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator=(const PmergeMe &rhs);

		~PmergeMe();

		const std::vector<int> &getMainV() const;
		const std::deque<int> &getMainD() const;

		void addInteger(const char *str);

		void sortVector();
		void sortDeque();

	private:
		std::vector<int> _mainV;
		std::deque<int> _mainD;

		void _sortPairsVector();
		void _moveMinsToPendantVector(std::vector<int> &pendant);
		void _moveMinsBackToMainVector(std::vector<int> &pendant);

		void _sortPairsDeque();
		void _moveMinsToPendantDeque(std::deque<int> &pendant);
		void _moveMinsBackToMainDeque(std::deque<int> &pendant);
};
