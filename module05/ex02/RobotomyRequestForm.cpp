/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:09:58 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 15:30:03 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45), _target("default")
{
	std::cout << CYAN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << CYAN << "RobotomyRequestForm( " << target << " ) constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << CYAN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs) {
	std::cout << GREEN << "RobotomyRequestForm assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		AForm::operator=(rhs);

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << BLUE << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExecRequirements(executor);

	std::cout << WHITE << "Dzzzzzzzzzzzzzzz..." << RESET << std::endl;

	srand(time(0));
	if (rand() % 2)
		std::cout << WHITE << _target << " has been successfully robotomized." << RESET << std::endl;
	else
		std::cout << WHITE << _target << " has failed to be robotomized." << RESET << std::endl;
}
