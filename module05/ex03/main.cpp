/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:39:14 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 16:19:29 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;

	Form* scf;
	Form* rrf;
	Form* ppf;
	Form* none;

	scf = someRandomIntern.makeForm("shrubbery creation", "Forest");
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Culprit");
	none = someRandomIntern.makeForm("test", "Yes");

	std::cout << *scf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *ppf << std::endl;

	{
		Bureaucrat b("Maxime", 138);
		b.signForm(*scf);
		b.signForm(*rrf);
		b.signForm(*ppf);
		b.executeForm(*scf);
		b.executeForm(*rrf);
		b.executeForm(*ppf);

		b.incrementGrade();

		b.executeForm(*scf);
		b.executeForm(*rrf);
		b.executeForm(*ppf);
	}
	{
		Bureaucrat b("Simon", 30);

		b.signForm(*rrf);
		b.signForm(*ppf);

		b.executeForm(*rrf);
		b.executeForm(*ppf);
	}
	{
		Bureaucrat b("Alex", 2);

		b.signForm(*ppf);
		b.executeForm(*ppf);
	}

	delete scf;
	delete rrf;
	delete ppf;
	delete none;

	return 0;
}
