/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:16:41 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/10 18:11:35 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

// # include <iostream>
# include "AMateria.hpp"
// # include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &other);

		Ice &operator=(const Ice &other);

		~Ice();

		void use(ICharacter& target);
		AMateria* clone() const;
};

#endif
