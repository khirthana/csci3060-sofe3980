/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362

This class is meant to contain simplified and modular usages of common functions
 */

#include <stdio.h>
#include <account.h>
#include <fstream>
#include <regex>
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Utilities{
public:

/* Generic prompt for all console output
 * output: represents what should be displayed on screen
 * acceptions: list of strings that are acceptable specific inputs from user (like standard/admin)
 * re: regular expression representing acceptable generic answers (for names etc)
 */

	string Prompt(string output, string reg ,list<string> acceptions){
	cout << output << endl;

		if (acceptions.size() != 0 and reg != "") {
			string input;
			cin >> input;

			for (int n = 0; n < acceptions.size(); n++) {
				//check if input is equal to one of them
				list<string>iterator it = acceptions.begin();
				for(int i=0; i<n; i++){
					++it;
				}

				if (*it == input) return input;
			}

			try {
				regex re(reg);
				smatch match;
				if (regex_search(input, match, re) && match.size() > 1) {
					return match.str(1);
				}
			} catch (regex_error& e) {
			}

			//if we have made it here, then there has been no match (ie incorrect input)
			cout << "Invalid input." << endl;
		} else { //if all we want to do is output to console (ie info)
			return "";
		}
	}

	list<Account> LoadAccountInformation(string accounts_file){
		//read through accounts file to get information about account holder

		string line;
		list<Account> accounts = {};
		fstream infile;
		infile.open(accounts_file);

		while (getline(infile, line)){
			Account account (line.substr(0,4),line.substr(6,25),line.substr(27,27),line.substr(29,36),line.substr(38,41));
			accounts.push_front(account);
		}
		infile.close();
		return accounts;
	}

	Account *GetAccountFromName(string name, list<Account> accounts){
		//get account information when input is account name

		bool found = false;
		list<Account>iterator it = accounts.begin();
		for(int i=0; i<accounts.size(); i++){
			if (it->getAccountName() == name){
				return &*it;
			}
			++it;
		}
		if (!found){
			return nullptr;
		}
	}

	Account *GetAccountFromNumber(double number, list<Account> accounts){
		//get account information when input is account number

		bool found = false;
		list<Account>iterator it = accounts.begin();
		for(int i=0; i<accounts.size(); i++){
			if (it->getAccountNumber() == number){
				return &*it;
			}
			++it;
		}
		if (!found){
			return nullptr;
		}
	}

};
