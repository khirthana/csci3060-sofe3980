/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362

This class contains functions to compute transactions on accounts 
*/

#include <account.h>
#include <utilities.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;


class AccountManager{
public:
	string transactions_log;
	list<Account> accounts_in_file;
	string session_type;
	Utilities utility_functions;
	Account* current_account;

	AccountManager(){
		this->transactions_log = "";
	}

	void Login(){
		//start of Session

		this->session_type = this->utility_functions.Prompt("Please Enter the Kind of Session: ","",{"standard","admin"});

		this->accounts_in_file = this->utility_functions.LoadAccountInformation("Accountsfile.txt");

		if(this->session_type=="standard"){
			string account_name = this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			this->current_account = utility_functions.GetAccountFromName(account_name,accounts_in_file);

			if (this->current_account == nullptr){
				this->utility_functions.Prompt("Invalid Account Name.");
			}
		}
	}

	void Withdrawal(){
		//withdraw amount from account

		if(session_type=="admin"){
			string account_name =  this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			this->current_account = this->utility_functions.GetAccountFromName(account_name,this->accounts_in_file);
			if (this->current_account == nullptr){
				this->utility_functions.Prompt("Invalid Account Name.");
			}
		}

		double account_number = (this->utility_functions.Prompt("Please Enter the Account Number: ","\\d{0,5}"));
		if (account_number != this->current_account->GetAccountNumber()){
			return;
		}

		double withdrawal_amount= (this->utility_functions.Prompt("Please Enter the Withdrawl Ammount: ","\\d{0,5}"));

		double current_balance = this->current_account->GetBalance();
		if ( current_balance > withdrawal_amount){
			current_account->setBalance(current_balance-withdrawal_amount);
			this->utility_functions.Prompt("Transaction successful.");
		}
		else{
			this->utility_functions.Prompt("Insufficient funds.");
		}


		//if successful withdrawal; add withdrawal transaction information in transactions_log list
		this->transactions_log.append("01 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+to_string(withdrawal_amount)+" "+this->current_account->GetAccountType()+"\n");
	}

	void Transfer(){
		//transfer amount to account2 from account1

		if(session_type=="admin"){
			string account_name = this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			this->current_account = this->utility_functions.GetAccountFromName(account_name,this->accounts_in_file);
			if (this->current_account == nullptr){
				this->utility_functions.Prompt("Invalid Account Name.");
			}
		}

		double account_number = (this->utility_functions.Prompt("Please Enter the Account Number: ","\\d{0,5}"));
		string account_number_to = "";
		double transfer_amount = 0;

		//if successful transfer; add transfer transaction information in transactions_log list
		this->transactions_log.append("01 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+to_string(transfer_amount)+" "+this->current_account->GetAccountType()+"\n");
		this->transactions_log.append("04 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+to_string(transfer_amount)+" "+this->current_account->GetAccountType()+"\n");

	}

	void Paybill(){
		//paybill amount from account to company

		if(session_type=="admin"){
			string account_name =  this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			this->current_account = this->utility_functions.GetAccountFromName(account_name,this->accounts_in_file);
			if (this->current_account == nullptr){
				this->utility_functions.Prompt("Invalid Account Name.");
			}
		}

		double account_number = stod(this->utility_functions.Prompt("Please Enter the Account Number: ","\\d{0,5}"));
		string company_paidto = "";
		double amount_to_pay = 0;

		//if successful paybill; add paybill transaction information in transactions_log list
		this->transactions_log.append("03 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+to_string(amount_to_pay)+" "+this->current_account->GetAccountType()+"\n");

	}

	void Deposit(){
		//deposit amount into account

		if(session_type=="admin"){
			string account_name =  this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			this->current_account = this->utility_functions.GetAccountFromName(account_name,this->accounts_in_file);
			if (this->current_account == nullptr){
				this->utility_functions.Prompt("Invalid Account Name.");
			}
		}

		double account_number = (this->utility_functions.Prompt("Please Enter the Account Number: ","\\d{0,5}"));
		double amount_deposit = 0;

		//if successful deposit; add deposit transaction information in transactions_log list
		this->transactions_log.append("04 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+to_string(amount_deposit)+" "+this->current_account->GetAccountType()+"\n");
	}

	void CreateAccount(){
		//create new account with unique account number

		if(session_type=="admin"){
			string account_name =  this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");

			//initial balance
			double account_balance = 0;

			//if account created; add account information in transactions_log list
			this->transactions_log.append("05 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+to_string(this->current_account->GetBalance())+" "+this->current_account->GetAccountType()+"\n");

		}
	}

	void DeleteAccount(){
		//delete account from system

		if(session_type=="admin"){
			string account_name =  this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			double account_number = (this->utility_functions.Prompt("Please Enter the Account Number: ","\\d{0,5}"));

		//if account deleted; add deleted account information in transactions_log list
		this->transactions_log.append("06 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+"      "+this->current_account->getAccountType()+"\n");
		}
	}

	void EnableAccount(){
		//enabe account; account status from D to A
		if(session_type=="admin"){
			string account_name =  this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			double account_number = (this->utility_functions.Prompt("Please Enter the Account Number: ","\\d{0,5}"));

			//if account enabled; add enabed account information in transactions_log list
			this->transactions_log.append("09 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+to_string(this->current_account->GetBalance())+" "+this->current_account->GetAccountStatus()+"\n");
		}
	}

	void DisableAccount(){
		//disable account; account status from A to D

		if(session_type=="admin"){
			string account_name =  this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			double account_number = stod(this->utility_functions.Prompt("Please Enter the Account Number: ","\\d{0,5}"));

			//if account disabled; add disabled account information in transactions_log list
			this->transactions_log.append("07 "+this->current_account->getAccountName()+" "+to_string(this->current_account->getAccountNumber())+" "+to_string(this->current_account->getBalance())+" "+this->current_account->getAccountStatus()+"\n");
		}
	}

	void ChangePlan(){
		//changeplan for account; account type should be change (S/NS)

		if(session_type=="admin"){
			string account_name =  this->utility_functions.Prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			double account_number = (this->utility_functions.Prompt("Please Enter the Account Number: ","\\d{0,5}"));

			//if account plan is changed; add account plan information in transactions_log list
			this->transactions_log.append("08 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+to_string(this->current_account->GetBalance())+" "+this->current_account->GetAccountType()+"\n");

		}
	}

	void Logout(){
		//end session

		//if logout; add logout information in transactions_log list
		this->transactions_log.append("00 "+this->current_account->GetAccountName()+" "+to_string(this->current_account->GetAccountNumber())+" "+"      "+this->current_account->GetAccountType()+"\n");

		//output transaction file log
		ifstream outfile;
		outfile.open("transaction_log.txt");
		outfile << this->transactions_log << endl;
		outfile.close();
	}
};
