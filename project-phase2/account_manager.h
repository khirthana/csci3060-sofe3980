/*
*
*/
#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <string>
#include <list>
#include <account.h>
#include <utilities.h>

class AccountManager{
public:
	std::string transactions_log  = "";
	std::list<Account> accounts_in_file;
	std::string session_type;
	Utilities utility_functions;
	Account* current_account;
	
	AccountManager(){
		Utilities util;
		this->utility_functions = util;
	}
	
	void login();
	void withdrawal();
	void transfer();
	void paybill();
	void deposit();
	void createAccount();
	void deleteAccount();
	void enableAccount();
	void disableAccount();
	void changePlan();
	void logout();
};

#endif