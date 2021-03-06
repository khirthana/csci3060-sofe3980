/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362
*This class contains functions to compute backend transactions on accounts
*/

package phase4;
import java.io.*;
import java.util.*;

public class BackEndSystem{
	/*
	reads in the previous day�s master bank accounts file and 
	then applies all of the bank account transactions from a merged set of bank account transaction files 
	to the old master bank accounts file to produce the new master bank accounts file. 
	Because transactions may also create or delete bank accounts, 
	it also produces a new current bank accounts file for tomorrow�s Front End runs
	
	Output: new Master Bank Accounts File, new Current Bank Accounts File
	*/
	
	
	/*
	 * General function to read the new transactions, apply to a simulated set of the real set and only make final change if valid
	 */
	public static List<Account> ValidateTransactions(List<Account> current_accounts,List<Account> n_accounts,List<String> transaction_list){
		List<String> transactions = transaction_list;
		List<Account> new_accounts = n_accounts;
		for (String transaction : transactions){

			String[] details_raw = transaction.split("\\s+");
			String[] details = {details_raw[0],details_raw[1],"","",""};
			
			int n = 2;
			for (; !Character.isDigit(details_raw[n].charAt(0));n++){
				details[1] += " " + details_raw[n];
			}
			
			while (n < details_raw.length){
				details[n-1] = details_raw[n];
				n++;
			}
			
			boolean account_old = true;
			Account current_account = Utilities.GetAccountFromNumber(details[2], current_accounts);
			if (current_account == null){
				account_old = false;
				
				current_account = Utilities.GetAccountFromNumber(details[2], new_accounts);
				if (current_account == null){
					System.out.println("ERROR: <Account in transaction does not exist>");
					return null;
				}
			}
			
			Account test = new Account(current_account.GetAccountNumber(),current_account.GetAccountName(),current_account.GetAccountStatus(),Double.toString(current_account.GetBalance()),current_account.GetAccountTransactions(),current_account.GetAccountType());
			
			//apply transaction to test account
			
			if (details[0].equals("01")){ // withdrawal
				test.SetBalance(test.GetBalance() - Double.valueOf(details[3]));
			}
			
			else if (details[0].equals("02")){ // transfer
				test.SetBalance(test.GetBalance() - Double.valueOf(details[3]));
				
			}
			
			else if (details[0].equals("03")){ // paybill
				test.SetBalance(test.GetBalance() - Double.valueOf(details[3]));
			}
			
			else if (details[0].equals("04")){ // deposit
				test.SetBalance(test.GetBalance() + Double.valueOf(details[3]));
			}
			
			else if (details[0].equals("05")){ // create
				Account new_account = new Account(details[2],details[1],"A",details[3],"0",details[4]);
				new_accounts.add(new_account);
			}
			
			else if (details[0].equals("06")){ // delete
				if (account_old == true)
					current_accounts.remove(current_account);
				else
					new_accounts.remove(current_account);
			}
			
			else if (details[0].equals("07")){ // disable
				test.SetAccountStatus(details[4]);
			}
			
			else if (details[0].equals("08")){ // changeplan
				test.SetAccountType(details[4]);
			}
			
			else if (details[0].equals("09")){ // enable
				test.SetAccountStatus(details[4]);
			}
			
			else{
				System.out.println("Transaction code invalid");
			}
			
			if (!Utilities.CheckForError(test, current_accounts,account_old)){
				// if valid, then replace current account with test (with transactions applied) 
				current_account = test;
				if ("01020304".contains(details[0]))
					current_account.IncrementAccountTransactions();
					Fee(current_account);
			}
		}
		return new_accounts;
	}
	
	
	/*
	 * Method designed to be used within a loop (if transaction is valid, fee(account))
	 */
	public static void Fee(Account account){
		account.SetBalance(account.GetBalance()-0.05); //charge 5 cents no matter what
		if (account.GetAccountType()== "N"){ //charge an extra 5 if not a student
			account.SetBalance(account.GetBalance()-0.05);
		}
	}
	
	@SuppressWarnings("null")
	public static void main(String [] args) throws IOException
	{
		
		
		String master_account_file=""; 
		String transaction_files_folder="";
			
		if (args.length > 0) {
			try {
					master_account_file=args[0]; 
					transaction_files_folder=args[1];
					  
			} catch (NumberFormatException e) {
					System.err.println("Inputs should be Master Bank Accounts Filename and Transactions Files Foldername");
					System.exit(1);
			}
		}
		
		//calls method to merge transaction files into MergedTransactionFile
		String merged_transaction_filename = Utilities.MergeTransactionFiles(transaction_files_folder);
		List<Account> accounts = Utilities.LoadAccountInformation(master_account_file);
		List<String> transactions = Utilities.LoadTransactions(merged_transaction_filename);
		List<Account> new_accounts = ValidateTransactions(accounts,new ArrayList<Account>(),transactions);
		
		Utilities.WriteAccounts(accounts,"MasterAccountsFile.txt");
		Utilities.WriteAccounts(new_accounts,"NewAccountsFile.txt");
		
	}
}