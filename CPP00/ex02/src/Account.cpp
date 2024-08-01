#include "Account.hpp"
#include <ctime>
#include <sstream>
#include <iostream>

#define BLUE "\033[34m"
#define RESET "\033[0m"

//Initialisation statics
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {

	//get the time in seconds
	std::time_t time_sec = time(0);

	//convert the time in tm structure
	std::tm *time_infos = std::localtime(&time_sec);
	
	//format the time into a string
	char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", time_infos);

	std::cout << "[" << buffer << "]";
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit) {
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex
		<< RESET << ";amount:" << BLUE << _amount
		<< RESET << ";created" << std::endl;
}

int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << " accounts:" << BLUE << getNbAccounts()
		<< RESET << ";total:" << BLUE << getTotalAmount()
		<< RESET << ";deposits:" << BLUE << getNbDeposits()
		<< RESET << ";withdrawals:" << BLUE << getNbWithdrawals()
		<< RESET << std::endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex
		<< RESET << ";amount:" << BLUE << _amount
		<< RESET << ";deposits:" << BLUE << _nbDeposits
		<< RESET << ";withdrawals:" << BLUE << _nbWithdrawals
		<< RESET << std::endl;
}

void Account::makeDeposit(int deposit) {
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex
		<< RESET << ";p_amount:" << BLUE << _amount
		<< RESET << ";deposit:" << BLUE << deposit
		<< RESET << ";amount:" << BLUE << _amount + deposit
		<< RESET << ";nb_deposits:" << BLUE << _nbDeposits
		<< RESET << std::endl;
	_amount += deposit;
}

int	Account::checkAmount(void) const {
	if (_amount < 0)
		return (1);
	return (0);
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex
		<< RESET << ";p_amount:" << BLUE << _amount << RESET;
	_amount -= withdrawal;
	if (checkAmount())
	{
		_amount += withdrawal;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << BLUE << withdrawal
			<< RESET << ";amount:" << BLUE << _amount
			<< RESET << "nb_withdrawals:" << BLUE << _nbWithdrawals
			<< RESET << std::endl;
		return (true);
	}
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << BLUE << _accountIndex
		<< RESET << ";amout:" << BLUE << _amount
		<< RESET << ";closed" << std::endl;
}
