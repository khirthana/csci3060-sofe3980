/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362
*/

#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <string>
#include <list>

using namespace std;

class AccountManager{
public:
	list<string>* transactions_log;
	list<Account> accounts_in_file;
	string session_type;
	Account logged_in_account;

	AccountManager();
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
