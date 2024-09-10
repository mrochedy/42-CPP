/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:38:21 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/10 18:11:41 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

// # include <iostream>
# include "AMateria.hpp"
// # include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &other);

		Cure &operator=(const Cure &other);

		~Cure();

		void use(ICharacter& target);
		AMateria* clone() const;
};

#endif
