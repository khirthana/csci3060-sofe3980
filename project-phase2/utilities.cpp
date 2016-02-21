/* This class is meant to contain simplified and modular usages of common functions
 *
 */
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Utilities{
 public:

	/* Generic prompt for all console output
	 * output: represents what should be displayed on screen
	 * acceptions: list of strings that are acceptable specific inputs from user (like standard/admin)
	 * re: regular expression representing acceptable generic answers (for names etc)
	 */
  string prompt(string output, string[] acceptions = [], string reg = ""){
		cout << output << endl;

		if (acceptions != empty and re != "") { //sudo code here, basically check to see if we are expecting an input
			string input;
			cin >> input;

			for (all in acceptions) {
				//check if input is equal to one of them
				if (yes) return input;
			}

			try {
			  regex re(reg);
			  smatch match;
			  if (regex_search(input, match, re) && match.size() > 1) {
				return match.str(1);
			  }
			} catch (std::regex_error& e) {
			}

			//if we have made it here, then there has been no match (ie incorrect input)
			cout << "Invalid input" << endl;
		} else { //if all we want to do is output to console (ie info)
			return "";
		}
	}
}
