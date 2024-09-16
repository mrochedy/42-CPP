/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:45:47 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 16:18:28 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << CYAN << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(Intern &other) {
	std::cout << CYAN << "Intern copy constructor called" << RESET << std::endl;
	*this = other;
}

Intern &Intern::operator=(Intern &rhs) {
	std::cout << GREEN << "Intern assignment operator called" << RESET << std::endl;

	(void)rhs;
	return *this;
}

Intern::~Intern() {
	std::cout << BLUE << "Intern destructor called" << RESET << std::endl;
}

Form *makeShrubberyForm(const std::string target) {
	return new ShrubberyCreationForm(target);
}

Form *makeRobotomyForm(const std::string target) {
	return new RobotomyRequestForm(target);
}

Form *makePresidentialForm(const std::string target) {
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(const std::string name, const std::string target) const {
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (*ptr[3])(const std::string t) = {&makeShrubberyForm, &makeRobotomyForm, &makePresidentialForm};

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << WHITE << "Intern creates " << name << RESET << std::endl;
			return ptr[i](target);
		}
	}

	std::cout << WHITE << "Intern could not create " << name
		<< ", no such form found." << RESET << std::endl;
	return NULL;
}
