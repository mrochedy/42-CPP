/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:24:37 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 15:02:45 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
const T &min(const T &a, const T &b) {
	return a < b ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b) {
	return a > b ? a : b;
}
