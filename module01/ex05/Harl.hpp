/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:06:30 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/07 11:32:19 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	public:
		Harl();
		void complain( std::string level );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
