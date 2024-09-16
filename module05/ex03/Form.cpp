/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:38:13 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 16:17:57 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signGrade(75), _execGrade(75) {
	std::cout << CYAN << "Form default constructor called" << RESET << std::endl;
	_isSigned = false;
}

Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << CYAN << "Form( " << name << ", " << signGrade << ", " << execGrade
		<< " ) constructor called" << RESET << std::endl;
	if (_signGrade <= 0 || _execGrade <= 0)
		throw GradeTooHighException();
	else if (_signGrade >= 151 || _execGrade >= 151)
		throw GradeTooLowException();
	_isSigned = false;
}

Form::Form(Form &other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << CYAN << "Form copy constructor called" << RESET << std::endl;
	*this = other;
}

Form &Form::operator=(Form &rhs) {
	std::cout << GREEN << "Form assignment operator called" << RESET << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;

	return *this;
}

Form::~Form() {
	std::cout << BLUE << "Form destructor called" << RESET << std::endl;
}

std::string Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void Form::checkExecRequirements(Bureaucrat const & executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char *Form::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	std::string signedOrNot = form.getIsSigned() ? "" : " not";

	os << GREEN << "Form " << form.getName() << " needs at least grade " << form.getSignGrade()
		<< " to get signed and at least grade " << form.getExecGrade() << " to get executed. "
		<< "It is" << signedOrNot << " signed." << RESET;
	return os;
}
