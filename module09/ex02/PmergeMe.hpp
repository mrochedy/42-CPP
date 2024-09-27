/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:10 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/27 15:14:47 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator=(const PmergeMe &rhs);

		~PmergeMe();

		const std::vector<int> &getMainV() const;
		const std::list<int> &getMainL() const;
		const std::deque<int> &getMainD() const;

		void addInteger(const char *str);

		void sortVector();
		void sortList();
		void sortDeque();

	private:
		std::vector<int> _mainV;
		std::list<int> _mainL;
		std::deque<int> _mainD;

		void _sortPairsVector();
		void _moveMinsToPendantVector(std::vector<int> &pendant);
		void _moveMinsBackToMainVector(std::vector<int> &pendant);

		void _sortPairsList();
		void _moveMinsToPendantList(std::list<int> &pendant);
		void _moveMinsBackToMainList(std::list<int> &pendant);

		void _sortPairsDeque();
		void _moveMinsToPendantDeque(std::deque<int> &pendant);
		void _moveMinsBackToMainDeque(std::deque<int> &pendant);
};
