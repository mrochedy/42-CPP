/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:30:11 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 14:42:13 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(AForm &other);

		AForm &operator=(AForm &rhs);

		virtual ~AForm();

		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getIsSigned() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void checkExecRequirements(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
