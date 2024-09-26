/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:13 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/26 17:40:13 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_v = rhs._v;
		_l = rhs._l;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

const std::vector<int> &PmergeMe::getV() const {
	return _v;
}

const std::list<int> &PmergeMe::getL() const {
	return _l;
}

void PmergeMe::addInteger(const char *str) {
	int j = 0;

	for (; str[j]; j++)
		if (str[j] < '0' || str[j] > '9')
			throw std::exception();

	if (j > 10)
		throw std::exception();

	long lnb = atol(str);
	if (lnb > INT_MAX)
		throw std::exception();

	int nb = lnb;

	_v.push_back(nb);
	_l.push_back(nb);
}

void PmergeMe::_sortPairs() {
	for (std::vector<int>::iterator it = _v.begin(); it < _v.end(); it++) {
		std::vector<int>::iterator prev = it;
		it++;

		if (it != _v.end()) {
			if (*prev > *it) {
				int tmp = *prev;
				*prev = *it;
				*it = tmp;
			}
		} else
			it = prev;
	}

	for (std::list<int>::iterator it = _l.begin(); it != _l.end(); it++) {
		std::list<int>::iterator prev = it;
		it++;

		if (it != _l.end()) {
			if (*prev > *it) {
				int tmp = *prev;
				*prev = *it;
				*it = tmp;
			}
		} else
			it = prev;
	}
}

void PmergeMe::_fillPendantAndMain() {
	for (std::vector<int>::iterator it = _v.begin(); it < _v.end(); it++) {
		std::vector<int>::iterator prev = it;
		it++;

		if (it != _v.end()) {
			_pendantV.push_back(*prev);
			_mainV.push_back(*it);
		} else {
			_mainV.push_back(*prev);
			it = prev;
		}
	}

	for (std::list<int>::iterator it = _l.begin(); it != _l.end(); it++) {
		std::list<int>::iterator prev = it;
		it++;

		if (it != _l.end()) {
			_pendantL.push_back(*prev);
			_mainL.push_back(*it);
		} else {
			_mainL.push_back(*prev);
			it = prev;
		}
	}
}

void PmergeMe::sort() {
	_sortPairs();
	_fillPendantAndMain();

	for (std::vector<int>::iterator it = _pendantV.begin(); it < _pendantV.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	for (std::vector<int>::iterator it = _mainV.begin(); it < _mainV.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	for (std::list<int>::iterator it = _pendantL.begin(); it != _pendantL.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	for (std::list<int>::iterator it = _mainL.begin(); it != _mainL.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}
