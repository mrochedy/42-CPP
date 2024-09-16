/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:09:58 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 15:21:27 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137), _target("default")
{
	std::cout << CYAN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << CYAN << "ShrubberyCreationForm( " << target << " ) constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << CYAN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs) {
	std::cout << GREEN << "ShrubberyCreationForm assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		AForm::operator=(rhs);

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << BLUE << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkExecRequirements(executor);

	std::ofstream file(std::string(_target + "_shrubbery").c_str());

	if (!file.is_open()) {
		std::cerr << "Shrubbery file cannot be created" << std::endl;
		return ;
	}
	file << "               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

	file.close();
}
