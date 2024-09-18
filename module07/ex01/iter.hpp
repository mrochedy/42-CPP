/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:05:05 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 15:18:22 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T1, typename F, typename T2>
void iter(T1 *array, int len, F (*foo)(T2 &)) {
	if (!array || !foo)
		return ;
	for (int i = 0; i < len; i++)
		foo(array[i]);
}
