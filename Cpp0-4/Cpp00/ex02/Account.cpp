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

}

Account::Account(int dep){
	this->_totalAmount++;
	this->_nbAccounts++;
	this->_totalNbDeposits++;
	this->_totalNbWithdrawals++;
	if (this->_accountIndex > 0)
		this->_accountIndex = _accountIndex + 1 % 8;
	this->_nbDeposits++;
	this->_amount = dep;
	this->_nbWithdrawals++;
	this->_displayTimestamp();
	std::cout << " index:"<< this->_accountIndex << ";amount:" << this->_amount << ";created"; 
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
