/* This class is meant to contain simplified and modular usages of common functions
 *
 */

#include <stdio.h>
#include <account.h>
#include <fstream>
#include <regex>
#include <list>
#include <iostream>
#include <string>

class Utilities{
public:

	/* Generic prompt for all console output
	 * output: represents what should be displayed on screen
	 * acceptions: list of strings that are acceptable specific inputs from user (like standard/admin)
	 * re: regular expression representing acceptable generic answers (for names etc)
	 */
	std::string prompt(std::string output, std::string reg ,std::list<std::string> acceptions){
		std::cout << output << std::endl;
			
		if (acceptions.size() != 0 and reg != "") {
			std::string input;
			std::cin >> input;

			for (int n = 0; n < acceptions.size(); n++) {
				//check if input is equal to one of them
				std::list<std::string>::iterator it = acceptions.begin();
				for(int i=0; i<n; i++){
					++it;
				}
				
				if (*it == input) return input;
			}

			try {
				std::regex re(reg);
				std::smatch match;
				if (std::regex_search(input, match, re) && match.size() > 1) {
					return match.str(1);
				}
			} catch (std::regex_error& e) {
			}

			//if we have made it here, then there has been no match (ie incorrect input)
			std::cout << "Invalid input." << std::endl;
		} else { //if all we want to do is output to console (ie info)
			return "";
		}
	}
	
	std::list<Account> loadAccountInformation(std::string accounts_file){
		//int element is the position in a line
		//(5 elements in a line:1-account number, 2-account name, 3-account status,4-account balance, 5-account type)

		//read through accounts file to get information about account holder
		std::string line;
		std::list<Account> accounts = {};
		std::fstream infile;
		infile.open(accounts_file);
		
		while (std::getline(infile, line)){
			Account account (line.substr(0,4),line.substr(6,25),line.substr(27,27),line.substr(29,36),line.substr(38,41));
			accounts.push_front(account);
		}
		infile.close();
		return accounts;
	}
	
	Account *getAccountFromName(std::string name, std::list<Account> accounts){
		bool found = false;
		std::list<Account>::iterator it = accounts.begin();
		for(int i=0; i<accounts.size(); i++){
			if (it->getAccountName() == name){
				return &*it;
				break;
			}
			++it;
		}
		if (!found){
			return nullptr;
		}
	}
	
};
