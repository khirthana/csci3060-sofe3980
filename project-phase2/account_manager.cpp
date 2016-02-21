/*
*
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class AccountManager{
 public:
	List<string> transactions_log = new List<string>();
	string accounts_file;
	string session_type;

  void Login(){
		//an example usage of the utilities
		session_type = utilities.prompt("Kind of session",["standard","admin"]);

		if(Account.session_type=="standard"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
		}

		 //prompt to input the current bank accountsfile
		 printf("Enter the name of current bank accounts file:\n");
     cin>>accounts_file;
	}

	void Withdrawal(){
		if(session_type=="admin"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
		}

		Account.account_number = utilities.prompt("Account number",reg="\u\l+ \u\l+");//not sure how to limit to 5 digits
		double withdrawal_amount=

		//withdraw amount from account


		//if successful withdrawal; add withdrawal transaction information in transactions_log list
		transactions_log.Add("01 "+Account.account_name+" "+Account.account_number+" "+withdrawal_amount+" "+Account.account_type);
	}

	void Transfer(){
		if(session_type=="admin"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
		}

		Account.account_number = utilities.prompt("Account number",reg="\u\l+ \u\l+");//not sure how to limit to 5 digits
		string account_number_to =
		double transfer_amount=

		//transfer amount to account2 from account1


		//if successful transfer; add transfer transaction information in transactions_log list
		transactions_log.Add("01 "+Account.account_name+" "+Account.account_number+" "+transfer_amount+" "+Account.account_type);
		transactions_log.Add("04 "+Account.account_name+" "+Account.account_number+" "+transfer_amount+" "+Account.account_type);

	}

	void Paybill(){
		if(session_type=="admin"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
		}

		Account.account_number = utilities.prompt("Account number",reg="\u\l+ \u\l+");//not sure how to limit to 5 digits
		string company_paidto=
		double amount_to_pay=

		//paybill amount to company


		//if successful paybill; add paybill transaction information in transactions_log list
		transactions_log.Add("03 "+Account.account_name+" "+Account.account_number+" "+amount_to_pay+" "+Account.account_type);

	}

	void Deposit(){
		if(session_type=="admin"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
		}

		Account.account_number = utilities.prompt("Account number",reg="\u\l+ \u\l+");//not sure how to limit to 5 digits
		double amount_deposit=

		//deposit amount


		//if successful deposit; add deposit transaction information in transactions_log list
		transactions_log.Add("04 "+Account.account_name+" "+Account.account_number+" "+amount_deposit+" "+Account.account_type);
	}

	void CreateAccount(){
		if(session_type=="admin"){
		  Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");

			//initial balance
			Account.account_balance=

			//create account with unique account number


			//if account created; add account information in transactions_log list
			transactions_log.Add("05 "+Account.account_name+" "+Account.account_number+" "+account_balance+" "+Account.account_type);

		}
	}

	void DeleteAccount(){
		if(session_type=="admin"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
			Account.account_number = utilities.prompt("Account number",reg="\u\l+ \u\l+");//not sure how to limit to 5 digits

		//delete account from system


		//if account deleted; add deleted account information in transactions_log list
		transactions_log.Add("06 "+Account.account_name+" "+Account.account_number+" "+"      "+Account.account_type);
		}
	}

	void EnableAccount(){
		if(session_type=="admin"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
			Account.account_number = utilities.prompt("Account number",reg="\u\l+ \u\l+");//not sure how to limit to 5 digits

			//enabe account; account status from D to A


			//if account enabled; add enabed account information in transactions_log list
			transactions_log.Add("09 "+Account.account_name+" "+Account.account_number+" "+Account.account_balance+" "+Account.account_status);
		}
	}

	void DisableAccount(){
		if(session_type=="admin"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
			Account.account_number = utilities.prompt("Account number",reg="\u\l+ \u\l+");//not sure how to limit to 5 digits

			//disable account; account status from A to D


			//if account disabled; add disabled account information in transactions_log list
			transactions_log.Add("07 "+Account.account_name+" "+Account.account_number+" "+Account.account_balance+" "+Account.account_status);
		}
	}

	void ChangePlan(){
		if(session_type=="admin"){
			Account.account_name =  utilities.prompt("Account holders name",reg="\u\l+ \u\l+");
			Account.account_number = utilities.prompt("Account number",reg="\u\l+ \u\l+");//not sure how to limit to 5 digits

			//changeplan for account; account type should be change (S/NS)


			//if account plan is changed; add account plan information in transactions_log list
			transactions_log.Add("08 "+Account.account_name+" "+Account.account_number+" "+Account.account_balance+" "+Account.account_type);

		}
	}

	void Logout(){
		//end session

		//if logout; add logout information in transactions_log list
		transactions_log.Add("00 "+Account.account_name+" "+Account.account_number+" "+"      "+Account.account_type);

		//output transaction file log
		for(std::list<std::string>::const_iterator i = transactions_log.begin(); i != transactions_log.end(); ++i){
			ofstream outfile;
		  outfile.open("transaction_log.txt");
      outfile << i->c_str() << endl;
      outfile.close();
		}

	}
}
