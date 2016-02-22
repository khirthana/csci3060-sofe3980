/*
*
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

class Account{
private:
	std::string account_name;
	double account_number;
	double account_balance;
	std::string account_type;
	std::string account_status;
public:
	Account(std::string number, std::string name, std::string status, std::string  balance , std::string type){
		this->account_name = name;
		this->account_number = std::stod(number);
		this->account_type = type;
		this->account_status = status;
		this->account_balance= std::stod(balance);
	}
	double getBalance(){
		//read through the accounts file & store the current balance of account holder
		return this->account_balance;
	}

	std::string getAccountType(){
		//read through the accounts file & store the account type of account holder (S/NS)
		return this->account_type;
	}

	std::string getAccountStatus(){
		//read through the accounts file & store the status of account holder (A/D)
		return this->account_status;
	}
	
	std::string getAccountName(){
		return this->account_name;
	}
	
	double getAccountNumber(){
		return this->account_number;
	}
	
	void setBalance(double balance){
		//read through the accounts file & store the current balance of account holder
		this->account_balance = balance;
	}

	void setAccountType(std::string type){
		//read through the accounts file & store the account type of account holder (S/NS)
		this->account_type = type;
	}

	void setAccountStatus(std::string status){
		//read through the accounts file & store the status of account holder (A/D)
		this->account_status = status;
	}
};
