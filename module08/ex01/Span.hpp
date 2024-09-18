/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:01:23 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 18:07:09 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);

		Span &operator=(const Span &rhs);

		~Span();

	private:
		int _maxLen;
		std::vector<int> _store;
};
