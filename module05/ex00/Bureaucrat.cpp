/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:25:30 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/24 09:54:11 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(75) {
	std::cout << CYAN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << CYAN << "Bureaucrat ( " << name << ", " << grade << " ) constructor called" << RESET << std::endl;
	if (grade <= 0)
		throw GradeTooHighException();
	else if (grade >= 151)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : _name(other._name) {
	std::cout << CYAN << "Bureaucrat copy constructor called" << RESET << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &rhs) {
	std::cout << GREEN << "Bureaucrat assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;

	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << BLUE << "Bureaucrat destructor called" << RESET << std::endl;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << YELLOW << _name << "'s grade has been incremented to " << _grade << RESET << std::endl;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << YELLOW << _name << "'s grade has been decremented to " << _grade << RESET << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high! Aborting...";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low! Aborting...";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << GREEN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.' << RESET;
	return os;
}
