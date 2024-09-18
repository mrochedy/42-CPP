/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:34:10 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/18 14:20:36 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

# define WHITE "\033[1;97m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[1;38;5;214m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

class Base {
	public:
		virtual ~Base();
};

#endif
