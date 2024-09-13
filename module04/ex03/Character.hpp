/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:57:11 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/13 14:03:28 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter;

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);

		Character &operator=(const Character &other);

		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		AMateria *getMateriaAddr(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria *_inventory[4];
};

#endif
