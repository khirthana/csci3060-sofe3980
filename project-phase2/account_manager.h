/*
*
*/
#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <string>
#include <vector>
#include <account.h>
#include <utilities.h>

class AccountManager{
public:
	std::string transactions_log;
	std::vector<Account> accounts_in_file;
	std::string session_type;
	Utilities utility_functions;
	Account* current_account;
	
	AccountManager(){
		Utilities util;
		this->transactions_log = "";
		this->utility_functions = util;
	}
	
	void Login();
	void Withdrawal();
	void Transfer();
	void Paybill();
	void Deposit();
	void CreateAccount();
	void DeleteAccount();
	void EnableAccount();
	void DisableAccount();
	void ChangePlan();
	void Logout();
};

#endif