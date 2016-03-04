/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362

This class contains functions to retrieve and store account information
*/

#include <stdio.h>
#include "Account.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Account::Account(string number, string name, string status, string  balance , string type){
	this->account_name = name;
	this->account_number = number;
	this->account_type = type;
	this->account_status = status;
	this->account_balance= stod(balance);
}

double Account::GetBalance(){
	//read through the accounts file & store the current balance of account holder
	return this->account_balance;
}

string Account::GetAccountType(){
	//read through the accounts file & store the account type of account holder (S/NS)
	return this->account_type;
}

string Account::GetAccountStatus(){
	//read through the accounts file & store the status of account holder (A/D)
	return this->account_status;
}

string Account::GetAccountName(){
	return this->account_name;
}

string Account::GetAccountNumber(){
	return this->account_number;
}

void Account::SetBalance(double balance){
	//read through the accounts file & store the current balance of account holder
	this->account_balance = balance;
}

void Account::SetAccountType(string type){
	//read through the accounts file & store the account type of account holder (S/NS)
	this->account_type = type;
}

void Account::SetAccountStatus(string status){
	//read through the accounts file & store the status of account holder (A/D)
	this->account_status = status;
}
