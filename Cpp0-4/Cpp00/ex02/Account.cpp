#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(){
	return (_nbAccounts);
}

int	Account::getTotalAmount(){
	return (_totalAmount);
}

int Account::getNbDeposits(){
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(){
	Account::_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

Account::Account(int dep){
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += dep;
	Account::_nbAccounts++;
		this->_accountIndex = (getNbAccounts() - 1) % 8;
	this->_amount = dep;
	Account::_displayTimestamp();
	std::cout << " index:"<< this->_accountIndex
	<< ";amount:" << checkAmount() << ";created"
	<< std::endl; 
}

int Account::checkAmount() const {
	return (this->_amount);
}

void Account::_displayTimestamp(){
	time_t curr_time = time(NULL);
	tm* locale_t = localtime(&curr_time);
	char buffer[50];
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", locale_t);
	std::cout << buffer ;
}

void	Account::displayStatus() const{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
	<< ";amount:" << this->checkAmount() << ";deposits:"
	<< this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

Account::~Account(){
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
	<< ";amount:" << this->checkAmount() << ";closed" << std::endl;
}

void	Account::makeDeposit(int dep){
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:"
	<< this->checkAmount() << ";deposit:" << dep
	<< ";amount:" << (this->checkAmount() + dep)
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += dep;
	this->_amount +=dep;
}

bool	Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:"
	<< this->checkAmount() << ";withdrawal:";
	if (withdrawal > checkAmount()){
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:"
	<< (this->checkAmount() - withdrawal) << ";nb_withdrawals:"
	<< this->_nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	return (true);
}
