/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:05:36 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/11 11:30:33 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;

	// std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other) {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	*this = other;

	// std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++)
		{
			if (this->_templates[i])
				delete this->_templates[i];

			if (rhs._templates[i])
				this->_templates[i] = rhs._templates[i]->clone();
			else
				this->_templates[i] = NULL;
		}
	}

	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_templates[i])
			delete _templates[i];

	// std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia) {
	int i = 0;

	for (; i < 4; i++)
		if (_templates[i] == NULL)
			break ;
	if (i < 4)
		_templates[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	AMateria *tmp;

	for (int i = 3; i >= 0; i--) {
		if (_templates[i] && _templates[i]->getType() == type) {
			tmp = _templates[i];
			_templates[i] = NULL;
			return (tmp);
		}
	}
	return (0);
}
