/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
		 James Morrison - 100524362
This class contains functions to retrieve and store account information
*/

package phase4;
import java.io.*;
import java.util.*;

public class Account{
	String account_name;
	String account_number;
	String account_type;
	int account_transactions;
	String account_status;
	double account_balance;

	Account(String number, String name, String status, String  balance , String transactions, String type){
		this.account_name = name;
		this.account_number = number;
		this.account_type = type;
		this.account_transactions = Integer.parseInt(transactions);
		this.account_status = status;
		this.account_balance= Double.parseDouble(balance);
	}
	
	public double GetBalance(){
		//returns the current balance of account holder
		return account_balance;
	}

	public String GetAccountType(){
		//returns the account type of account holder (S/NS)
		return account_type;
	}

	public String GetAccountStatus(){
		//returns the status of account holder (A/D)
		return account_status;
	}

	public String GetAccountName(){
		//returns account holder name
		return account_name;
	}

	public String GetAccountNumber(){
		//returns account number
		return account_number;
	}
	
	public String GetAccountTransactions(){
		//returns account transactions
		return Integer.toString(account_transactions);
	}
	
	public void SetBalance(double balance){
		//stores the current balance of account holder
		this.account_balance = balance;
	}

	public void SetAccountType(String type){
		//stores the account type of account holder (S/NS)
		this.account_type = type;
	}

	public void SetAccountStatus(String status){
		//stores the status of account holder (A/D)
		this.account_status = status;
	}
	
	public void IncrementAccountTransactions(){
		this.account_transactions++;
	}
}


