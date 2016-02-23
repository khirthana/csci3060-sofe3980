/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account{
private:
	string account_name;
	double account_number;
	double account_balance;
	string account_type;
  string account_status;

public:
	Account(string  number, string name, string status, string balance , string type);

	double getBalance();
	string getAccountType();
	string getAccountStatus();
	string getAccountName();
	double getAccountNumber();
	void setBalance(double balance);
	void setAccountType(string type);
	void setAccountStatus(string status);
};

#endif
