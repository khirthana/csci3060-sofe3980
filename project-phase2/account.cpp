/*
*
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

class Account{
 public:
  string privileges;//not sure if we need this


	string account_name;
	string account_number;
	double account_balance;
	string account_type;
	string account_status;

	double GetBalance(account_name,account_number){
		//read through the accounts file & store the current balance of account holder
		account_balance=GetAccountInformation(4);
	}

	string GetAccountType(account_name,account_number){
			//read through the accounts file & store the account type of account holder (S/NS)
		account_type=GetAccountInformation(5);
	}

	string GetAccountStatus(account_name,account_number){
			//read through the accounts file & store the status of account holder (A/D)
		account_status=GetAccountInformation(3);
	}


 string GetAccountInformation(int element){
	 //int element is the position in a line
	 //(5 elements in a line:1-account number, 2-account name, 3-account status,4-account balance, 5-account type)

	 //read through accounts file to get information about account holder
	 string data;

	 ifstream infile;
	 infile.open(account_manager.accounts_file);

	 //read line by line & extract the element required


	 infile.close();
	 return data;
 }


}
