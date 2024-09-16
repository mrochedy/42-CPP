/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:30:11 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/16 16:17:03 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(Form &other);

		Form &operator=(Form &rhs);

		virtual ~Form();

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
