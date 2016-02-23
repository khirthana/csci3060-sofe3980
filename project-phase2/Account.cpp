/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362

This class contains functions to retrieve and store account information
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Account{

private:
	string account_name;
	double account_number;
	double account_balance;
	string account_type;
	string account_status;

public:
	Account(string number,string name, string status, string  balance , string type){
		this->account_name = name;
		this->account_number = atoi(number.c_str());
		this->account_type = type;
		this->account_status = status;
		this->account_balance = atof(balance.c_str());
	}

	double GetBalance(){
		return this->account_balance;
	}

	string GetAccountType(){
		return this->account_type;
	}

	string GetAccountStatus(){
		return this->account_status;
	}

	string getAccountName(){
		return this->account_name;
	}

	double getAccountNumber(){
		return this->account_number;
	}

	void setBalance(double balance){
		this->account_balance = balance;
	}

	void setAccountType(string type){
		this->account_type = type;
	}

	void setAccountStatus(string status){
		this->account_status = status;
	}
};
