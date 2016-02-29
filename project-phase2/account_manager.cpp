/*
*
*/
#include <account.h>
#include <utilities.cpp>
#include <account_manager.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <list>

void AccountManager::login(){
	//an example usage of the this->utility_functions
	this->session_type = Utilities::prompt("Please Enter the Kind of Session: ","standard|admin");
	
	this->accounts_in_file = Utilities::loadAccountInformation("Accountsfile.txt");
	
	if(this->session_type=="standard"){
		std::string account_name = Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		this->current_account = Utilities::getAccountFromName(account_name,accounts_in_file);
		
		if (this->current_account == nullptr){
			Utilities::prompt("Invalid Account Name.");
		}
	}
}

void AccountManager::withdrawal(){
	if(session_type=="admin"){
		std::string account_name =  Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		this->current_account = Utilities::getAccountFromName(account_name,this->accounts_in_file);
		if (this->current_account == nullptr){
			Utilities::prompt("Invalid Account Name.");
		}
	}
	
	
	double account_number = std::stod(Utilities::prompt("Please Enter the Account Number: ","\\d{0,5}"));
	if (account_number != this->current_account->getAccountNumber()){
		return;
	}
		
	double withdrawal_amount= std::stod(Utilities::prompt("Please Enter the Withdrawl Ammount: ","\\d{0,5}")); //needs changing reg to upper amount limit
	double current_balance = this->current_account->getBalance();
	if ( current_balance > withdrawal_amount){
		current_account->setBalance(current_balance-withdrawal_amount);
		Utilities::prompt("Transaction successful.");
	}
	else{
		Utilities::prompt("Insufficient funds.");
	}


	//if successful withdrawal; add withdrawal transaction information in transactions_log list
	this->transactions_log.append("01 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(withdrawal_amount)+" "+this->current_account->getAccountType()+"\n");
}

void AccountManager::transfer(){
	if(session_type=="admin"){
		std::string account_name = Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		this->current_account = Utilities::getAccountFromName(account_name,this->accounts_in_file);
		if (this->current_account == nullptr){
			Utilities::prompt("Invalid Account Name.");
		}
	}

	double account_number = std::stod(Utilities::prompt("Please Enter the Account Number: ","\\d{0,5}"));
	std::string account_number_to = "";
	double transfer_amount = 0;

	//transfer amount to account2 from account1


	//if successful transfer; add transfer transaction information in transactions_log list
	this->transactions_log.append("01 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(transfer_amount)+" "+this->current_account->getAccountType()+"\n");
	this->transactions_log.append("04 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(transfer_amount)+" "+this->current_account->getAccountType()+"\n");

}

void AccountManager::paybill(){
	if(session_type=="admin"){
		std::string account_name =  Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		this->current_account = Utilities::getAccountFromName(account_name,this->accounts_in_file);
		if (this->current_account == nullptr){
			Utilities::prompt("Invalid Account Name.");
		}
	}

	double account_number = std::stod(Utilities::prompt("Please Enter the Account Number: ","\\d{0,5}"));
	std::string company_paidto = "";
	double amount_to_pay = 0;

	//paybill amount to company


	//if successful paybill; add paybill transaction information in transactions_log list
	this->transactions_log.append("03 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(amount_to_pay)+" "+this->current_account->getAccountType()+"\n");

}

void AccountManager::deposit(){
	if(session_type=="admin"){
		std::string account_name =  Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		this->current_account = Utilities::getAccountFromName(account_name,this->accounts_in_file);
		if (this->current_account == nullptr){
			Utilities::prompt("Invalid Account Name.");
		}
	}

	double account_number = std::stod(Utilities::prompt("Please Enter the Account Number: ","\\d{0,5}"));
	double amount_deposit = 0;

	//deposit amount


	//if successful deposit; add deposit transaction information in transactions_log list
	this->transactions_log.append("04 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(amount_deposit)+" "+this->current_account->getAccountType()+"\n");
}

void AccountManager::createAccount(){
	if(session_type=="admin"){
		std::string account_name =  Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");

		//initial balance
		double account_balance = 0;

		//create account with unique Please Enter the Account Number: 


		//if account created; add account information in transactions_log list
		this->transactions_log.append("05 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(this->current_account->getBalance())+" "+this->current_account->getAccountType()+"\n");

	}
}

void AccountManager::deleteAccount(){
	if(session_type=="admin"){
		std::string account_name =  Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		double account_number = std::stod(Utilities::prompt("Please Enter the Account Number: ","\\d{0,5}"));

	//delete account from system


	//if account deleted; add deleted account information in transactions_log list
	this->transactions_log.append("06 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+"      "+this->current_account->getAccountType()+"\n");
	}
}

void AccountManager::enableAccount(){
	if(session_type=="admin"){
		std::string account_name =  Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		double account_number = std::stod(Utilities::prompt("Please Enter the Account Number: ","\\d{0,5}"));

		//enabe account; account status from D to A


		//if account enabled; add enabed account information in transactions_log list
		this->transactions_log.append("09 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(this->current_account->getBalance())+" "+this->current_account->getAccountStatus()+"\n");
	}
}

void AccountManager::disableAccount(){
	if(session_type=="admin"){
		std::string account_name =  Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		double account_number = std::stod(Utilities::prompt("Please Enter the Account Number: ","\\d{0,5}"));

		//disable account; account status from A to D


		//if account disabled; add disabled account information in transactions_log list
		this->transactions_log.append("07 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(this->current_account->getBalance())+" "+this->current_account->getAccountStatus()+"\n");
	}
}

void AccountManager::changePlan(){
	if(session_type=="admin"){
		std::string account_name =  Utilities::prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		double account_number = std::stod(Utilities::prompt("Please Enter the Account Number: ","\\d{0,5}"));
		//changeplan for account; account type should be change (S/NS)


		//if account plan is changed; add account plan information in transactions_log list
		this->transactions_log.append("08 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+std::to_string(this->current_account->getBalance())+" "+this->current_account->getAccountType()+"\n");

	}
}

void AccountManager::logout(){
	//end session

	//if logout; add logout information in transactions_log list
	this->transactions_log.append("00 "+this->current_account->getAccountName()+" "+std::to_string(this->current_account->getAccountNumber())+" "+"      "+this->current_account->getAccountType()+"\n");

	//output transaction file log
	std::fstream outfile;
	outfile.open("transaction_log.txt");
	outfile << this->transactions_log << std::endl;
	outfile.close();
}


int main(int argc, char **argv)
{
	AccountManager accounts = AccountManager();
	accounts.login();
	return 0;
}
