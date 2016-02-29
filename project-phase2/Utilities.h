/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362
*/

#include <stdio.h>
#include <account.h>
#include <fstream>
#include <regex>
#include <list>
#include <iostream>
#include <string>


#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities{
public:
	static std::string prompt(std::string output, std::string reg = "", std::list<std::string> acceptions = {});
	static std::list<Account> loadAccountInformation(std::string accounts_file);
	static Account *getAccountFromName(std::string name, std::list<Account> accounts);
	static Account *getAccountFromNumber(double number, std::list<Account> accounts);
};

#endif
