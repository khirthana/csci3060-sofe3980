/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362
*/

#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <string>
#include <list>
#include "Account.h"
#include "Utilities.h"

class AccountManager{
public:

	std::list<Account> accounts_in_file;
	Account* current_account;
	std::string session_type;
	std::string account_name;
	std::string account_number;
	std::string transaction;
	std::string transactions_log  = "";
	std::string transaction_file_name;

	//Utilities utility_functions;


	// AccountManager(){
	// 	Utilities util;
	// 	this->utility_functions = util;
	// }

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
	void TransactionCall(string transaction);
};

#endif
