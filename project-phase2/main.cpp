/*
*
*/

#include <string>
#include <stdio.h>
#include <iostream>


int main(int argc, char **argv){

	printf("Banking System\n");

	printf("Enter the transaction you want to do this session:\n");

	string input;

	cin>>input;

	if(input == "login") {
    account_manager.login();
	} else {
		printf("You have to login in order to process transactions\n");
	}



	return 0;
}
