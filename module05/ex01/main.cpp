/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:39:14 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 13:36:36 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form f("Employment contract", 10, 10);

	std::cout << f << std::endl;

	Bureaucrat b1("Maxime", 11);

	b1.signForm(f);
	std::cout << f << std::endl;

	b1.incrementGrade();

	b1.signForm(f);
	std::cout << f << std::endl;

	return 0;
}
