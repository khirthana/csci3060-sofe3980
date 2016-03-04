/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362

This class contains functions to compute transactions on accounts
*/

#include "Account.h"
#include "Utilities.cpp"
#include "Account_Manager.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

void AccountManager::Login(){
//start of Session

	session_type= Utilities::Prompt("Please Enter the Kind of Session (standard/admin):",{"standard|admin"});

	//if session is standard then, prompts account name; if invalid input then prompts again
	if(session_type=="standard"){
		bool input_valid=false;
		while(input_valid==false){
			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
				Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
			Utilities::Prompt("Valid Account Name.");
				input_valid=true;

				transaction=Utilities::Prompt("Enter next transaction: ");//appropriate function will be called to compute transaction request
				TransactionCall(transaction);
			}
		}
	}
}

void AccountManager::Withdrawal(){
//withdraw amount from account

	if(session_type=="admin"){

	  bool input_valid=false;
		while(input_valid==false){
			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
				Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
						Utilities::Prompt("Valid Account Name.");
				input_valid=true;
			}
		}
	}

//prompts account number; if invalid prompts again
	bool input_number_valid=false;
	while(input_number_valid==false){
		account_number = (Utilities::Prompt("Please Enter the Account Number: ","\\d{5}"));

		if (account_number != this->current_account->getAccountNumber()){
					Utilities::Prompt("Input Account Number is invalid.");
		}else{
			input_number_valid=true;
		}
	}

double withdrawal_amount;
withdrawal_amount= stod(Utilities::Prompt("Please Enter the intial Account Balance: ","\\d{5}\\.\\d{2}|\\d{1}\\.\\d{2}|\\.\\d{2}"));

if(this->current_account->getAccountStatus()=="A"){
	//transaction fee is charged
	if(this->current_account->getAccountType()=="S"){
		current_account->setBalance(current_balance-0.05);
	}else{
		current_account->setBalance(current_balance-0.10);
	}

	if (current_balance > withdrawal_amount){
		current_account->setBalance(current_balance-withdrawal_amount);
		Utilities::Prompt("Transaction successful.");

		Utilities::Prompt("Transaction fee deducted.");

		//adds withdrawal transaction information in transactions_log list
		this->transactions_log.append("01 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+to_string(withdrawal_amount)+" "+this->current_account->getAccountType()+"\n");

		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);
	}else{
		Utilities::Prompt("Insufficient funds.");
		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);

		//transaction fee is reimboursed as transaction is denied
		if(this->current_account->getAccountType()=="S"){
			current_account->setBalance(current_balance+0.05);
		}else{
			current_account->setBalance(current_balance+0.10);
		}
			Utilities::Prompt("Transaction fee not deducted.");
	}
}else{
Utilities::Prompt("Transaction unsuccessful. Account is already disabled.");
transaction=Utilities::Prompt("Enter next transaction: ");
TransactionCall(transaction);
}
}

void AccountManager::Transfer(){
//transfer amount to account2 from account1

	if(session_type=="admin"){

		bool input_valid=false;
		while(input_valid==false){
			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
					Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
				Utilities::Prompt("Valid Account Name.");
				input_valid=true;
			}
		}
	}
		//prompts account number; if invalid prompts again
		bool input_number_valid=false;
		while(input_number_valid==false){
			account_number = (Utilities::Prompt("Please Enter the Account Number: ","\\d{5}"));

			if (account_number != this->current_account->getAccountNumber()){
				Utilities::Prompt("Input Account Number is invalid.");
			}else{
				input_number_valid=true;
			}
		}

		//prompts account transferred to; verify if account number is valid in current accounts list; if invalid prompts again
		bool input_number_to_valid=false;
		while(input_number_to_valid==false){
			string account_number_to = "";
			account_number_to = (Utilities::Prompt("Please Enter the account transferred to: ","\\d{5}"));

			Account* transfer_account = Utilities::GetAccountFromNumber(account_number_to,accounts_in_file);
			if (transfer_account == nullptr){
				Utilities::Prompt("Input Account Number transferred to is invalid.");
			}else{
				input_number_to_valid=true;
			}
		}

	double transfer_amount = 0;

	transfer_amount= stod(Utilities::Prompt("Please Enter the intial Account Balance: ","\\d{5}\\.\\d{2}|\\d{1}\\.\\d{2}|\\.\\d{2}"));

	double current_balance = this->current_account->getBalance();
if(this->current_account->getAccountStatus()=="A"){
	//transaction fee is charged
	if(this->current_account->getAccountType()=="S"){
		current_account->setBalance(current_balance-0.05);
	}else{
		current_account->setBalance(current_balance-0.10);
	}

	if (current_balance > transfer_amount){
		//transfer amount to account2 from account1 (update account balance)
		current_account->setBalance(current_balance-transfer_amount);
		Utilities::Prompt("Transaction successful.");

		Utilities::Prompt("Transaction fee deducted.");

		//adds transfer transaction information in transactions_log list
		this->transactions_log.append("01 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+to_string(transfer_amount)+" "+this->current_account->getAccountType()+"\n");
		this->transactions_log.append("04 "+transfer_account->getAccountName()+" "+to_string(transfer_account->getAccountNumber())+" "+to_string(transfer_amount)+" "+transfer_account->getAccountType()+"\n");

		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);

	}else{
		Utilities::Prompt("Insufficient funds.");
		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);

		//transaction fee is reimboursed as transaction is denied
		if(this->current_account->getAccountType()=="S"){
			current_account->setBalance(current_balance+0.05);
		}else{
			current_account->setBalance(current_balance+0.10);
		}
			Utilities::Prompt("Transaction fee not deducted.");
	}
}else{
Utilities::Prompt("Transaction unsuccessful. Account is already disabled.");
transaction=Utilities::Prompt("Enter next transaction: ");
TransactionCall(transaction);
}
}

void AccountManager::Paybill(){
//paybill amount from account to company

	if(session_type=="admin"){

		bool input_valid=false;
		while(input_valid==false){
			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
				Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
				Utilities::Prompt("Valid Account Name.");
				input_valid=true;
			}
		}
	}

	//prompts account number; if invalid prompts again
		bool input_number_valid=false;
		while(input_number_valid==false){
			account_number =(Utilities::Prompt("Please Enter the Account Number: ","\\d{5}"));

			if (account_number != this->current_account->getAccountNumber()){
				Utilities::Prompt("Input Account Number is invalid.");
			}else{
				input_number_valid=true;
			}
		}

	string company_paidto = "";
	company_paidto=Utilities::Prompt("Please Enter the Company initial paid to: ","[A-z]{2}");

	double amount_to_pay = 0;
	amount_to_pay=stod(Utilities::Prompt("Please Enter the intial Account Balance: ","\\d{5}\\.\\d{2}|\\d{1}\\.\\d{2}|\\.\\d{2}"));

	double current_balance = this->current_account->getBalance();

	if(this->current_account->getAccountStatus()=="A"){
		//transaction fee is charged
		if(this->current_account->getAccountType()=="S"){
			current_account->setBalance(current_balance-0.05);
		}else{
			current_account->setBalance(current_balance-0.10);
		}

		if (current_balance > amount_to_pay){
			//paybill amount to company (update account balance)
			current_account->setBalance(current_balance-amount_to_pay);
			Utilities::Prompt("Transaction successful.");

			Utilities::Prompt("Transaction fee deducted.");

			//adds paybill transaction information in transactions_log list
			this->transactions_log.append("03 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+to_string(amount_to_pay)+" "+this->current_account->getAccountType()+"\n");

			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);

		}else{
			Utilities::Prompt("Insufficient funds.");
			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);

			//transaction fee is reimboursed as transaction is denied
			if(this->current_account->getAccountType()=="S"){
				current_account->setBalance(current_balance+0.05);
			}else{
				current_account->setBalance(current_balance+0.10);
			}
				Utilities::Prompt("Transaction fee not deducted.");
		}
}else{
	Utilities::Prompt("Transaction unsuccessful. Account is already disabled.");
	transaction=Utilities::Prompt("Enter next transaction: ");
	TransactionCall(transaction);
	}
}

void AccountManager::Deposit(){
//deposit amount into account

	if(session_type=="admin"){

		bool input_valid=false;
		while(input_valid==false){
			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
				Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
				Utilities::Prompt("Valid Account Name.");
				input_valid=true;
			}
		}
	}

	//prompts account number; if invalid prompts again
		bool input_number_valid=false;
		while(input_number_valid==false){
			account_number = (Utilities::Prompt("Please Enter the Account Number: ","\\d{5}"));

			if (account_number != this->current_account->getAccountNumber()){
				Utilities::Prompt("Input Account Number is invalid.");
			}else{
				input_number_valid=true;
			}
		}

	double amount_deposit = 0;
	amount_deposit=stod(Utilities::Prompt("Please Enter the intial Account Balance: ","\\d{5}\\.\\d{2}|\\d{1}\\.\\d{2}|\\.\\d{2}"));
	double current_balance = this->current_account->getBalance();

	if(this->current_account->getAccountStatus()=="A"){
		//transaction fee is charged
		if(this->current_account->getAccountType()=="S"){
			current_account->setBalance(current_balance-0.05);
		}else{
			current_account->setBalance(current_balance-0.10);
		}

		if (current_balance > amount_deposit){
			//deposit amount (update account balance)
			current_account->setBalance(current_balance+amount_deposit);
			Utilities::Prompt("Transaction successful.");

			Utilities::Prompt("Transaction fee deducted.");

			//adds deposit transaction information in transactions_log list
			this->transactions_log.append("04 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+to_string(amount_deposit)+" "+this->current_account->getAccountType()+"\n");

			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);

		}else{
			Utilities::Prompt("Insufficient funds.");
			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);}

			//transaction fee is reimboursed as transaction is denied
			if(this->current_account->getAccountType()=="S"){
				current_account->setBalance(current_balance+0.05);
			}else{
				current_account->setBalance(current_balance+0.10);
			}

			Utilities::Prompt("Transaction fee not deducted.");
	}else{
		Utilities::Prompt("Transaction unsuccessful. Account is already disabled.");
		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);
		}
}


void AccountManager::CreateAccount(){
//create new account with unique account number

	if(session_type=="admin"){
account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

		//initial balance
		double account_balance = 0;
		account_balance=stod(Utilities::Prompt("Please Enter the intial Account Balance: ","\\d{5}\\.\\d{2}|\\d{1}\\.\\d{2}|\\.\\d{2}"));

		//create account with unique Account Number; go through account numbers in accounts & select unique account number
		bool account_number_valid=false;
		while(account_number_valid==false){
		srand(time(NULL));
		int random_number=(rand()%10000)+1;
		string new_account_number=Integer.parseInt(random_number);
		if(new_account_number.size()<5)
		{
			switch (new_account_number.size()) {
				  case 1:
						new_account_number="0000"+new_account_number;
						break;
				  case 2:
						new_account_number="000"+new_account_number;
						break;
				  case 3:
				    new_account_number="00"+new_account_number;
				    break;
				  case 4:
				    new_account_number="0"+new_account_number;
						break;
  			}
		}
		Account* account_verify = Utilities::GetAccountFromNumber(new_account_number,accounts_in_file);

		if (this->account_verify == nullptr){
			account_number_valid=true;
		}
	}
		Utilities::Prompt("Transaction successful. Account created");

		//adds account information in transactions_log list
		this->transactions_log.append("05 "+account_name+" "+to_string(new_account_number)+" "+to_string(account_balance)+" "+"N"+"\n");

		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);
	}else{
		Utilities::Prompt("Transaction unsuccessful. Priviledge transactions are accepted in admin login session");
		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);
	}
}

void AccountManager::DeleteAccount(){
//delete account from system

	if(session_type=="admin"){

		bool input_valid=false;
		while(input_valid==false){
			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");
			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
				 Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
				 Utilities::Prompt("Valid Account Name.");
				input_valid=true;
			}
		}

		//prompts account number; if invalid prompts again
		bool input_number_valid=false;
		while(input_number_valid==false){
			account_number = (Utilities::Prompt("Please Enter the Account Number: ","\\d{5}"));

			if (account_number != this->current_account->getAccountNumber()){
				 Utilities::Prompt("Input Account Number is invalid.");
			}else{
				input_number_valid=true;
			}
		}

	//delete account from accounts list
	accounts_in_file.erase(current_account);

	Utilities::Prompt("Transaction successful. Account deleted");

	//if account deleted; add deleted account information in transactions_log list
	this->transactions_log.append("06 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+"      "+this->current_account->getAccountType()+"\n");

	transaction=Utilities::Prompt("Enter next transaction: ");
	TransactionCall(transaction);
}else{
		Utilities::Prompt("Transaction unsuccessful. Priviledge transactions are accepted in admin login session");
		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);
	}
	}



void AccountManager::EnableAccount(){
//enabe account; account status from D to A

	if(session_type=="admin"){

	  bool input_valid=false;
		while(input_valid==false){
			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
				 Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
				 Utilities::Prompt("Valid Account Name.");
				input_valid=true;
			}
		}

		//prompts account number; if invalid prompts again
		bool input_number_valid=false;
		while(input_number_valid==false){
			account_number = (Utilities::Prompt("Please Enter the Account Number: ","\\d{5}"));

			if (account_number != this->current_account->getAccountNumber()){
				Utilities::Prompt("Input Account Number is invalid.");
			}else{
				input_number_valid=true;
			}
		}

		if(this->current_account->getAccountStatus()=="D"){
				//enabe account; account status from D to A in accounts list
				current_account->setAccountStatus("A");
			}else{
				Utilities::Prompt("Transaction unsuccessful. Account is already active.");
				transaction=Utilities::Prompt("Enter next transaction: ");
				TransactionCall(transaction);
			}

			Utilities::Prompt("Transaction successful. Account Enabled");

		//if account enabled; add enabed account information in transactions_log list
		this->transactions_log.append("09 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+to_string(this->current_account->getBalance())+" "+this->current_account->getAccountStatus()+"\n");

		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);
	}else{
			Utilities::Prompt("Transaction unsuccessful. Priviledge transactions are accepted in admin login session");
			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);
		}
	}


void AccountManager::DisableAccount(){
//disable account; account status from A to D

	if(session_type=="admin"){

	  bool input_valid=false;
		while(input_valid==false){
			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
								 Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
			 Utilities::Prompt("Valid Account Name.");
				input_valid=true;
			}
		}

		//prompts account number; if invalid prompts again
		bool input_number_valid=false;
		while(input_number_valid==false){
			account_number = (Utilities::prompt("Please Enter the Account Number: ","\\d{5}"));

			if (account_number != this->current_account->getAccountNumber()){
				Utilities::Prompt("Input Account Number is invalid.");
			}else{
				input_number_valid=true;
			}
		}

	if(this->current_account->getAccountStatus()=="A"){
			//disable account; account status from A to D
			current_account->setAccountStatus("D");
		}else{
			Utilities::Prompt("Transaction unsuccessful. Account is already disabled.");
			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);
		}

		Utilities::Prompt("Transaction successful. Account disabled");

		//if account disabled; add disabled account information in transactions_log list
		this->transactions_log.append("07 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+to_string(this->current_account->getBalance())+" "+this->current_account->getAccountStatus()+"\n");

		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);
	}else{
			Utilities::Prompt("Transaction unsuccessful. Priviledge transactions are accepted in admin login session");
			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);
		}
	}


void AccountManager::ChangePlan(){
//account plan change; student or non-student (S/N)

	if(session_type=="admin"){

	  bool input_valid=false;
		while(input_valid==false){

			account_name = Utilities::Prompt("Please Enter the Name of the Account Holder: ","[A-z\s]{1,20}");

			current_account = Utilities::getAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
					 Utilities::Prompt("Invalid Account Name.");
			}else{
				//if account name is valid then prompts next transaction
				 Utilities::Prompt("Valid Account Name.");
				input_valid=true;
			}
		}

		//prompts account number; if invalid prompts again
		bool input_number_valid=false;
		while(input_number_valid==false){
			account_number =(Utilities::Prompt("Please Enter the Account Number: ","\\d{5}"));

			if (account_number != this->current_account->getAccountNumber()){
				Utilities::Prompt("Input Account Number is invalid.");
			}else{
				input_number_valid=true;
			}
		}

		//account plan is changed depending on their current plan
		if(current_account->getAccountType()=="S"){
				current_account->setAccountType("N");
		}else{
			current_account->setAccountType("S");
		}

		Utilities::Prompt("Transaction successful. Account type changed");

		//if account plan is changed; add account plan information in transactions_log list
		this->transactions_log.append("08 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+to_string(this->current_account->getBalance())+" "+this->current_account->getAccountType()+"\n");

		transaction=Utilities::Prompt("Enter next transaction: ");
		TransactionCall(transaction);
		}else{
			Utilities::Prompt("Transaction unsuccessful. Priviledge transactions are accepted in admin login session");
			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);
		}
	}



void AccountManager::Logout(){
	//end session

	//adds logout information in transactions_log list
	this->transactions_log.append("00 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+"      "+this->current_account->getAccountType()+"\n");

	//output transaction file log
	fstream outfile;
	outfile.open(transaction_file_name);
	outfile << this->transactions_log << endl;
	outfile.close();
}

//calls appropriate funstion to proceed transaction, if invalid transaction input then prompts to input next transaction again
void AccountManager::TransactionCall(string transaction_request){

	bool transaction_valid=false;

	while(transaction_valid==false){

		if(transaction_request=="withdrawal"||transaction_request=="Withdrawal"){
			 Withdrawal();
			 transaction_valid=true;
		}else if(transaction_request=="transfer"||transaction_request=="Transfer"){
			 Transfer();
			 transaction_valid=true;
		}else	if(transaction_request=="paybill"||transaction_request=="Paybill"){
			 paybill();
			 transaction_valid=true;
		}else if(transaction_request=="deposit"||transaction_request=="Deposit"){
			Deposit();
			transaction_valid=true;
		}else if(transaction_request=="create"||transaction_request=="Create"){
			CreateAccount();
			transaction_valid=true;
		}else if(transaction_request=="delete"||transaction_request=="Delete"){
			DeleteAccount();
			transaction_valid=true;
		}else if(transaction_request=="enable"||transaction_request=="Enable"){
			EnableAccount();
			transaction_valid=true;
		}else if(transaction_request=="disable"||transaction_request=="Disable"){
			DisableAccount();
			transaction_valid=true;
		}else if(transaction_request=="changeplan"||transaction_request=="Changeplan"){
			ChangePlan();
			transaction_valid=true;
		}else if(transaction_request=="logout"||transaction_request=="Logout"){
				Logout();
				transaction_valid=true;
		}else{
			Utilities::Prompt("Transaction invalid. Transaction options:withdrawal,transfer,paybill,deposit,create,delete,enable,disable,changeplan,logout.");
			transaction=Utilities::Prompt("Enter next transaction: ");
			TransactionCall(transaction);
		}
	}
}


int main(int argc, char *argv[])
{
	string accounts_file_name;

	//reads command line arguments and stores file names
	for(int i = 0; i < argc; i++){
		 accounts_file_name=argv[1];
		 transaction_file_name=argv[2];
	 }

	//loads accounts information from current accounts file
	this->accounts_in_file = Utilities::loadAccountInformation(accounts_file_name);

	//prompts to enter transaction and if input is different than login, prompts again to login
	bool login_valid=false;
	while(login_valid==false){

		transaction=Utilities::Prompt("Enter transaction to begin: ");
		TransactionCall(transaction);

		if(transaction=="login"){
			Utilities::Prompt("Login successful.");
			login_valid=true;
			Login();
		}else{
			Utilities::Prompt("User have to login in order to process further transactions.");
		}
	}

	return 0;
}
