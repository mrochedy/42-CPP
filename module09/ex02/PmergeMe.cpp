/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:02:13 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/27 15:09:57 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_mainV = rhs._mainV;
		_mainL = rhs._mainL;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

const std::vector<int> &PmergeMe::getMainV() const {
	return _mainV;
}

const std::list<int> &PmergeMe::getMainL() const {
	return _mainL;
}

const std::deque<int> &PmergeMe::getMainD() const {
	return _mainD;
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

	_mainV.push_back(nb);
	_mainL.push_back(nb);
	_mainD.push_back(nb);
}

void PmergeMe::_sortPairsVector() {
	for (std::vector<int>::iterator it = _mainV.begin(); it < _mainV.end(); it++) {
		std::vector<int>::iterator prev = it;
		it++;

		if (it != _mainV.end()) {
			if (*prev > *it) {
				int tmp = *prev;
				*prev = *it;
				*it = tmp;
			}
		} else
			it = prev;
	}
}

void PmergeMe::_moveMinsToPendantVector(std::vector<int> &pendant) {
	for (std::vector<int>::iterator it = _mainV.begin(); it < _mainV.end(); it++) {
		std::vector<int>::iterator prev = it;

		pendant.push_back(*prev);
		it = _mainV.erase(prev);
	}
}

void PmergeMe::_moveMinsBackToMainVector(std::vector<int> &pendant) {
	size_t pendant_size = pendant.size();
	size_t a = 1;
	size_t b = 3;
	size_t i = a - 1;

	while (pendant_size > 0 && pendant.back() >= 0) {
		while (i < pendant_size && i >= 0 && pendant[i] >= 0) {
			std::vector<int>::iterator pos;

			if (pendant[i] < _mainV.front())
				pos = _mainV.begin();
			else
				pos = std::lower_bound(_mainV.begin(), _mainV.end(), pendant[i]);

			_mainV.insert(pos, pendant[i]);
			pendant[i] = -1;
			i--;
		}

		size_t tmp = a;
		a = b;
		b += 2 * tmp;
		i = a - 1;
		if (i >= pendant_size)
			i = pendant_size - 1;
	}
}

void PmergeMe::sortVector() {
	_sortPairsVector();

	if (_mainV.size() <= 2)
		return ;

	std::vector<int> pendant;
	_moveMinsToPendantVector(pendant);

	sortVector();

	_moveMinsBackToMainVector(pendant);
}

void PmergeMe::_sortPairsDeque() {
	for (std::deque<int>::iterator it = _mainD.begin(); it < _mainD.end(); it++) {
		std::deque<int>::iterator prev = it;
		it++;

		if (it != _mainD.end()) {
			if (*prev > *it) {
				int tmp = *prev;
				*prev = *it;
				*it = tmp;
			}
		} else
			it = prev;
	}
}

void PmergeMe::_moveMinsToPendantDeque(std::deque<int> &pendant) {
	for (std::deque<int>::iterator it = _mainD.begin(); it < _mainD.end(); it++) {
		std::deque<int>::iterator prev = it;

		pendant.push_back(*prev);
		it = _mainD.erase(prev);
	}
}

void PmergeMe::_moveMinsBackToMainDeque(std::deque<int> &pendant) {
	size_t pendant_size = pendant.size();
	size_t a = 1;
	size_t b = 3;
	size_t i = a - 1;

	while (pendant_size > 0 && pendant.back() >= 0) {
		while (i < pendant_size && i >= 0 && pendant[i] >= 0) {
			std::deque<int>::iterator pos;

			if (pendant[i] < _mainD.front())
				pos = _mainD.begin();
			else
				pos = std::lower_bound(_mainD.begin(), _mainD.end(), pendant[i]);

			_mainD.insert(pos, pendant[i]);
			pendant[i] = -1;
			i--;
		}

		size_t tmp = a;
		a = b;
		b += 2 * tmp;
		i = a - 1;
		if (i >= pendant_size)
			i = pendant_size - 1;
	}
}

void PmergeMe::sortDeque() {
	_sortPairsDeque();

	if (_mainD.size() <= 2)
		return ;

	std::deque<int> pendant;
	_moveMinsToPendantDeque(pendant);

	sortDeque();

	_moveMinsBackToMainDeque(pendant);
}

void PmergeMe::_sortPairsList() {
	for (std::list<int>::iterator it = _mainL.begin(); it != _mainL.end(); it++) {
		std::list<int>::iterator prev = it;
		it++;

		if (it != _mainL.end()) {
			if (*prev > *it) {
				int tmp = *prev;
				*prev = *it;
				*it = tmp;
			}
		} else
			it = prev;
	}
}

void PmergeMe::_moveMinsToPendantList(std::list<int> &pendant) {
	for (std::list<int>::iterator it = _mainL.begin(); it != _mainL.end(); it++) {
		std::list<int>::iterator prev = it;

		pendant.push_back(*prev);
		it = _mainL.erase(prev);
	}
}

void PmergeMe::_moveMinsBackToMainList(std::list<int> &pendant) {
	size_t pendant_size = pendant.size();
	size_t a = 1;
	size_t b = 3;

	std::list<int>::iterator valIt = pendant.begin();

	while (pendant_size > 0 && pendant.back() >= 0) {
		while (valIt != pendant.end() && *valIt >= 0) {
			std::list<int>::iterator pos;
			if (*valIt < _mainL.front())
				pos = _mainL.begin();
			else
				pos = std::lower_bound(_mainL.begin(), _mainL.end(), *valIt);

			_mainL.insert(pos, *valIt);
			*valIt = -1;
			if (valIt != pendant.begin())
				valIt--;
		}

		size_t tmp = a;
		a = b;
		b += 2 * tmp;

		valIt = pendant.begin();

		std::list<int>::iterator last = pendant.end();
		last--;

		for (size_t j = 0; j != a - 1 && valIt != last; j++)
			valIt++;
	}
}

void PmergeMe::sortList() {
	_sortPairsList();

	if (_mainL.size() <= 2)
		return ;

	std::list<int> pendant;
	_moveMinsToPendantList(pendant);

	sortList();

	_moveMinsBackToMainList(pendant);
}
