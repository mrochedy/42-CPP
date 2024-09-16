/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:38:13 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 14:42:18 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signGrade(75), _execGrade(75) {
	std::cout << CYAN << "AForm default constructor called" << RESET << std::endl;
	_isSigned = false;
}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << CYAN << "AForm( " << name << ", " << signGrade << ", " << execGrade
		<< " ) constructor called" << RESET << std::endl;
	if (_signGrade <= 0 || _execGrade <= 0)
		throw GradeTooHighException();
	else if (_signGrade >= 151 || _execGrade >= 151)
		throw GradeTooLowException();
	_isSigned = false;
}

AForm::AForm(AForm &other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << CYAN << "AForm copy constructor called" << RESET << std::endl;
	*this = other;
}

AForm &AForm::operator=(AForm &rhs) {
	std::cout << GREEN << "AForm assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;

	return *this;
}

AForm::~AForm() {
	std::cout << BLUE << "AForm destructor called" << RESET << std::endl;
}

std::string AForm::getName() const {
	return _name;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::checkExecRequirements(Bureaucrat const & executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	std::string signedOrNot = form.getIsSigned() ? "" : " not";

	os << GREEN << "Form " << form.getName() << " needs at least grade " << form.getSignGrade()
		<< " to get signed and at least grade " << form.getExecGrade() << " to get executed. "
		<< "It is" << signedOrNot << " signed." << RESET;
	return os;
}
