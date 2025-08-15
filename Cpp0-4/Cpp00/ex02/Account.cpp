#include "Account.hpp"
#include <iostream>
#include <ctime>

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
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawls:" << Account::_totalNbWithdrawals
	<< std::endl;
}

Account::Account(int dep){
	this->_totalAmount++;
	this->_nbAccounts++;
	// this->_totalNbDeposits++; only in withdrawals
	// this->_totalNbWithdrawals++; only in make withdrawal
	if (this->_accountIndex > 0)
		this->_accountIndex = _accountIndex + 1 % 8;
	// this->_nbDeposits++; only in make deposit 
	this->_amount = dep;
	// this->_nbWithdrawals++; only in withdrawals
	this->_displayTimestamp();
	std::cout << " index:"<< this->_accountIndex
	<< ";amount:" << this->_amount << ";created"
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
	this->_displayTimestamp;
	std::cout << " index:" << this->_accountIndex
	<< ";amount:" << this->checkAmount() << ";deposits:"
	<< this->getNbDeposits() << ";withdrawals:" << this->getNbWithdrawals()
	<< std::endl;
}

Account::~Account(){
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
	<< ";amount:" << this->checkAmount() << ";closed" << std::endl;
}

void	Account::makeDeposit(int dep){
	this->_nbDeposits = dep;
	this->_totalNbDeposits++;
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:"
	<< this->checkAmount() << ";deposit:" << this->_nbDeposits
	<< ";amount:" << (this->checkAmount() + _nbDeposits)
	<< ";nb_deposts:" << this->getNbDeposits() << std::endl;

}

bool	Account::makeWithdrawal(int withdrawal){
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:"
	<< this->checkAmount() << ";withdrawal:";
	if (withdrawal > this->getNbDeposits()){
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals = withdrawal;
	this->_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:"
	<< (this->checkAmount() - withdrawal) << ";nb_withdrawals:"
	<< this->_totalNbWithdrawals;
	return (true);
}