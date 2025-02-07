/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:44:54 by mait-taj          #+#    #+#             */
/*   Updated: 2025/02/06 10:21:09 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void ) {
	return ;
}

Account::Account( int initial_deposit ) {
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex += _nbAccounts;
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account( void ) {
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t	current;
	tm	*local_time;
	
	time(&current);
	local_time = localtime(&current);
	std::string	timestamp;
	timestamp.resize(80);
	strftime(&timestamp[0], timestamp.size(), "%Y%m%d_%H%m%S", local_time);
	std::cout << timestamp;
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit ) {
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits += _nbDeposits;
	std::cout << ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount << ";withdrawal:";
	if ( withdrawal > _amount )
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal
		<< ":amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return (true);
}

int	Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
		<< "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

void	Account::displayStatus( void ) const {
	std::cout << "[";
	_displayTimestamp();
	std::cout << "] "
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}
