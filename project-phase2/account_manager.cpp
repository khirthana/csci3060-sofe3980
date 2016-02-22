/*
*
*/
#include <account.h>
#include <utilities.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <list>


class AccountManager{
public:
	std::list<std::string>* transactions_log = new std::list<std::string>();
	std::list<Account> accounts_in_file;
	std::string session_type;
	Utilities utility_functions;
	Account* current_account;

	void login(){
		//an example usage of the this->utility_functions
		this->session_type = this->utility_functions.prompt("Please Enter the Kind of Session: ","",{"standard","admin"});
		
		this->accounts_in_file = this->utility_functions.loadAccountInformation("Accountsfile.txt");
		
		if(this->session_type=="standard"){
			std::string account_name = this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			Account* current_account = utility_functions.getAccountFromName(account_name,accounts_in_file);
			
			if (this->current_account == nullptr){
				this->utility_functions.prompt("Invalid Account Name.");
			}
		}
	}

	void withdrawal(){
		if(session_type=="admin"){
			std::string account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			current_account = this->utility_functions.getAccountFromName(account_name,this->accounts_in_file);
			if (this->current_account == nullptr){
				this->utility_functions.prompt("Invalid Account Name.");
			}
		}

		account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");
		double withdrawal_amount=

		//withdraw amount from account


		//if successful withdrawal; add withdrawal transaction information in transactions_log list
		transactions_log.Add("01 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+withdrawal_amount+" "+this->currentAccount.account_type);
	}

	void transfer(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		}

		account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");//not sure how to limit to 5 digits
		std::string account_number_to =
		double transfer_amount=

		//transfer amount to account2 from account1


		//if successful transfer; add transfer transaction information in transactions_log list
		transactions_log.Add("01 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+transfer_amount+" "+this->currentAccount.account_type);
		transactions_log.Add("04 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+transfer_amount+" "+this->currentAccount.account_type);

	}

	void paybill(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		}

		account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");
		std::string company_paidto=
		double amount_to_pay=

		//paybill amount to company


		//if successful paybill; add paybill transaction information in transactions_log list
		transactions_log.Add("03 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+amount_to_pay+" "+this->currentAccount.account_type);

	}

	void deposit(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
		}

		account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");
		double amount_deposit=

		//deposit amount


		//if successful deposit; add deposit transaction information in transactions_log list
		transactions_log.Add("04 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+amount_deposit+" "+this->currentAccount.account_type);
	}

	void createAccount(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");

			//initial balance
			account_balance=

			//create account with unique Please Enter the Account Number: 


			//if account created; add account information in transactions_log list
			transactions_log.Add("05 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+account_balance+" "+this->currentAccount.account_type);

		}
	}

	void deleteAccount(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");

		//delete account from system


		//if account deleted; add deleted account information in transactions_log list
		transactions_log.Add("06 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+"      "+this->currentAccount.account_type);
		}
	}

	void enableAccount(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");

			//enabe account; account status from D to A


			//if account enabled; add enabed account information in transactions_log list
			transactions_log.Add("09 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+this->currentAccount.account_balance+" "+this->currentAccount.account_status);
		}
	}

	void disableAccount(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");

			//disable account; account status from A to D


			//if account disabled; add disabled account information in transactions_log list
			transactions_log.Add("07 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+this->currentAccount.account_balance+" "+this->currentAccount.account_status);
		}
	}

	void changePlan(){
		if(session_type=="admin"){
			account_name =  this->utility_functions.prompt("Please Enter the Name of the Account Holder: ","\\u\\l+ \\u\\l+");
			account_number = this->utility_functions.prompt("Please Enter the Account Number: ","\\d{0,5}");

			//changeplan for account; account type should be change (S/NS)


			//if account plan is changed; add account plan information in transactions_log list
			transactions_log.Add("08 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+this->currentAccount.account_balance+" "+this->currentAccount.account_type);

		}
	}

	void logout(){
		//end session

		//if logout; add logout information in transactions_log list
		transactions_log.Add("00 "+this->currentAccount.account_name+" "+this->currentAccount.account_number+" "+"      "+this->currentAccount.account_type);

		//output transaction file log
		for(std::list<std::string>::const_iterator i = transactions_log.begin(); i != transactions_log.end(); ++i){
			ofstream outfile;
			outfile.open("transaction_log.txt");
			outfile << i->c_str() << endl;
			outfile.close();
		}

	}
};
