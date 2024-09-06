/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:54:58 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/06 15:13:51 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie( void );
		void announce( void );
	private:
		std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
