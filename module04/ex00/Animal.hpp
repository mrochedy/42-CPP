/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:18:04 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/09 15:58:42 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &rhs);

		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType() const;

	protected:
		std::string _type;
};

#endif
