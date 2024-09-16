/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:09:58 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 16:20:56 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("presidential pardon", 25, 5), _target("default")
{
	std::cout << CYAN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("presidential pardon", 25, 5), _target(target)
{
	std::cout << CYAN << "PresidentialPardonForm( " << target << " ) constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
	: Form(other), _target(other._target)
{
	std::cout << CYAN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &rhs) {
	std::cout << GREEN << "PresidentialPardonForm assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		Form::operator=(rhs);

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << BLUE << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkExecRequirements(executor);
	std::cout << WHITE << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
