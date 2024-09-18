/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:14:01 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 13:26:25 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# define WHITE "\033[1;97m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;38;5;214m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

typedef struct s_Data {
	int val;
	std::string str;
} Data;

class Serializer {
	public:
		Serializer &operator=(Serializer &rhs);

		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer &other);

};

# endif
