/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:17:04 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/10 10:37:14 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int size = 10;

	const Animal *animals_array[size];
	int i = 0;

	for (; i < size / 2; i++)
		animals_array[i] = new Dog();
	for (; i < size ; i++)
		animals_array[i] = new Cat();

	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat(*cat1);

	cat2->makeSound();

	delete cat1;
	delete cat2;

	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog(*dog1);

	dog2->makeSound();

	delete dog1;
	delete dog2;

	animals_array[0]->makeSound();
	animals_array[size - 1]->makeSound();

	for (int j = 0; j < size; j++)
		delete(animals_array[j]);
	return 0;
}
