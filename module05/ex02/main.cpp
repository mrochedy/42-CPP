/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:39:14 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 15:33:51 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	ShrubberyCreationForm scf("Forest");
	RobotomyRequestForm rrf("Cyborg");
	PresidentialPardonForm ppf("Culprit");

	std::cout << scf << std::endl;
	std::cout << rrf << std::endl;
	std::cout << ppf << std::endl;

	{
		Bureaucrat b("Maxime", 138);
		b.signForm(scf);
		b.signForm(rrf);
		b.signForm(ppf);
		b.executeForm(scf);
		b.executeForm(rrf);
		b.executeForm(ppf);

		b.incrementGrade();

		b.executeForm(scf);
		b.executeForm(rrf);
		b.executeForm(ppf);
	}
	{
		Bureaucrat b("Simon", 30);

		b.signForm(rrf);
		b.signForm(ppf);

		b.executeForm(rrf);
		b.executeForm(ppf);
	}
	{
		Bureaucrat b("Alex", 2);

		b.signForm(ppf);
		b.executeForm(ppf);
	}

	return 0;
}
