/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:26:50 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/13 14:07:04 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	MateriaSource src2;
	src2.learnMateria(new Cure());

	Character attacker("attacker");
	Character defender("defender");

	attacker.equip(new Ice());
	attacker.equip(src2.createMateria("test"));
	attacker.equip(src2.createMateria("cure"));

	attacker.use(0, defender);
	attacker.use(1, defender);

	AMateria *tmp0 = attacker.getMateriaAddr(0);
	attacker.unequip(0);
	delete tmp0;

	attacker.use(0, defender);
	attacker.use(1, defender);

	AMateria *tmp1 = attacker.getMateriaAddr(1);
	attacker.unequip(1);
	delete tmp1;

	attacker.use(0, defender);
	attacker.use(1, defender);

	AMateria *tmp2 = attacker.getMateriaAddr(1);
	attacker.unequip(2);
	delete tmp2;

	return 0;
}
