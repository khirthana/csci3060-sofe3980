<<<<<<< HEAD
#include <stdio.h>
#include <account_manager.h>

int main1(int argc, char **argv)
{
	AccountManager accounts;
=======
/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362
*/

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
	printf("Banking System\n");

	printf("Enter the transaction you want to do this session:\n");

	string input;

	cin>>input;

	if (input == "login") {
		AccountManager.login();
	} else {
		printf("You have to login in order to process transactions\n");
	}

>>>>>>> origin/master
	return 0;
}
