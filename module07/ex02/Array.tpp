/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:35:33 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 16:37:28 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]()), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : _array(NULL) {
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	if (this != &rhs) {
		if (_array)
			delete[] _array;
		if (rhs._array) {
			_array = new T[rhs._size]();
			for (size_t i = 0; i < rhs._size; i++)
				_array[i] = rhs._array[i];
		}
		else
			_array = NULL;

		_size = rhs._size;
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index) {
	if (!_array || index >= _size)
		throw OutOfBoundsException();

	return _array[index];
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
size_t Array<T>::size() const {
	return _size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
	return "Accessed index is out of bounds!";
}
