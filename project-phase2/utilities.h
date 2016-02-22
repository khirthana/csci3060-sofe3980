/* This class is meant to contain simplified and modular usages of common functions
 *
 */
#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <list>
#include <string>

class Utilities{
public:
	std::string prompt(std::string output, std::string reg = "", std::list<std::string> acceptions = {});
	std::list<Account> loadAccountInformation(std::string accounts_file);
	Account *getAccountFromName(std::string name, std::list<Account> accounts);
};

#endif
