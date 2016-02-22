/*
*
*/
#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <string>
#include <list>

class AccountManager;
public:
	std::list<std::string>* transactions_log;
	std::list<Account> accounts_in_file;
	std::string session_type;
	Account logged_in_account;

	AccountManager();
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