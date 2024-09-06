/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:54:58 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 15:25:08 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
	public:
		Zombie( void );
		Zombie(std::string name);
		~Zombie( void );
		void announce( void );
		void setName( std::string name );
	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
