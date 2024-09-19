/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:12:03 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/19 11:43:20 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxLen(0) {}

Span::Span(unsigned int n) : _maxLen(n) {}

Span::Span(const Span &other) : _maxLen() {
	*this = other;
}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_maxLen = rhs._maxLen;
		_store = rhs._store;
	}

	return *this;
}

Span::~Span() {}

void Span::addNumber(int nb) {
	if (_store.size() >= _maxLen)
		throw TooManyElementsException();
	_store.insert(nb);
}

unsigned int Span::shortestSpan() const {
	if (_store.size() < 2)
		throw NotEnoughElementsException();

	std::multiset<int>::iterator prev = _store.begin();
	std::multiset<int>::iterator it = prev;
	it++;

	unsigned int shortest = *it - *_store.begin();
	unsigned int span;

	for (; it != _store.end(); it++) {
		span = *it - *prev;
		if (span < shortest)
			shortest = span;
		prev = it;
	}

	return (shortest);
}

unsigned int Span::longestSpan() const {
	if (_store.size() < 2)
		throw NotEnoughElementsException();
	return (*_store.rbegin() - *_store.begin());
}

void Span::addNumbersRange(std::multiset<int>::iterator begin, std::multiset<int>::iterator end) {
	if (_maxLen - _store.size() < (unsigned int)std::distance(begin, end))
		throw TooManyElementsException();
	_store.insert(begin, end);
}

const char *Span::TooManyElementsException::what() const throw() {
	return "Maximum limit of stored elements reached.";
}

const char *Span::NotEnoughElementsException::what() const throw() {
	return "Not enough stored elements to find a span.";
}
