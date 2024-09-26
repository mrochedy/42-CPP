/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:10 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/26 17:33:06 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <list>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);

		PmergeMe &operator=(const PmergeMe &rhs);

		~PmergeMe();

		const std::vector<int> &getV() const;
		const std::list<int> &getL() const;

		void addInteger(const char *str);
		void sort();

	private:
		std::vector<int> _v;
		std::vector<int> _pendantV;
		std::vector<int> _mainV;

		std::list<int> _l;
		std::list<int> _pendantL;
		std::list<int> _mainL;

		void _sortPairs();
		void _fillPendantAndMain();
};
