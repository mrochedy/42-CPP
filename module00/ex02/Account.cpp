/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:24:04 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/07 14:21:54 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdio>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	static int index = 0;

	_accountIndex = index;
	index++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";amount:"
		<< _amount << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;
}

std::string int_to_string(int nb, std::size_t minimum_size) {
	std::stringstream ss;
	ss << nb;

	std::string str_nb = ss.str();

	if (str_nb.size() < minimum_size)
        return std::string(minimum_size - str_nb.size(), '0') + str_nb;
    return str_nb;
}

void Account::_displayTimestamp() {
	std::time_t now = std::time(0);
	struct tm* localTime = std::localtime(&now);

	std::cout << '[' << int_to_string(localTime->tm_year + 1900, 4)
		<< int_to_string(localTime->tm_mon + 1, 2) << int_to_string(localTime->tm_mday, 2)
		<< '_' << int_to_string(localTime->tm_hour, 2) << int_to_string(localTime->tm_min, 2)
		<< int_to_string(localTime->tm_sec, 2) << "] ";
}

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:"
		<< _totalAmount << ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
		<< _amount << ";deposit:" << deposit << ";amount:"
		<< _amount + deposit << ";nb_deposits:" << 1 << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
		<< _amount << ";withdrawal:";
	if (_amount >= withdrawal)
	{
		std::cout << withdrawal << ";amount:"
			<< _amount - withdrawal << ";nb_withdrawals:"
			<< 1 << std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

int Account::checkAmount() const {
	return _totalAmount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";amount:"
		<< _amount << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
