#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
public :
	std::string account_name;
	double account_number;
	double account_balance;
	std::string account_type;
	std::string account_status;
	
	Account(std::string  number, std::string name, std::string status, std::string balance , std::string type);
	
	double getBalance();
	std::string getAccountType();
	std::string getAccountStatus();
	std::string getAccountName();
	double getAccountNumber();
	void setBalance(double balance);
	void setAccountType(std::string type);
	void setAccountStatus(std::string status);
};
 
#endif