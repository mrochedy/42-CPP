/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:04 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/09 16:09:33 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(j);
	delete(i);

	Dog doggy;
	Cat lil_cat;
	Animal random_animal;

	std::cout << doggy.getType() << std::endl;
	std::cout << lil_cat.getType() << std::endl;
	std::cout << random_animal.getType() << std::endl;

	doggy.makeSound();
	lil_cat.makeSound();
	random_animal.makeSound();

	return 0;
}
