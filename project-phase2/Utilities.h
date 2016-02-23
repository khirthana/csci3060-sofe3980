/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <list>
#include <string>

using namespace std;

class Utilities{
public:
	string Prompt(string output, string reg = "", list<string> acceptions = {});
	list<Account> LoadAccountInformation(string accounts_file);
	Account *GetAccountFromName(string name, list<Account> accounts);
	Account *GetAccountFromNumber(double number, list<Account> accounts);
};

#endif
