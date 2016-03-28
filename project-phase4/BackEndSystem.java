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
	reads in the previous day’s master bank accounts file and 
	then applies all of the bank account transactions from a merged set of bank account transaction files 
	to the old master bank accounts file to produce the new master bank accounts file. 
	Because transactions may also create or delete bank accounts, 
	it also produces a new current bank accounts file for tomorrow’s Front End runs
	
	Output: new Master Bank Accounts File, new Current Bank Accounts File
	*/
	
	
	/*
	 * General function to read the new transactions, apply to a simulated set of the real set and only make final change if valid
	 */
	public static void ValidateTransactions(List<Account> current_accounts,ArrayList<Account> new_accounts,String[] transaction_list){
		String[] transactions = transaction_list;
		for (String transaction : transactions){
			String[] details = transaction.split("\\s+");
			
			Account current_account = Utilities.GetAccountFromNumber(details[2], current_accounts);
			Account test = new Account(current_account.GetAccountNumber(),current_account.GetAccountName(),current_account.GetAccountStatus(),Double.toString(current_account.GetBalance()),current_account.GetAccountTransactions(),current_account.GetAccountType());
			
			//apply transaction to test account
			
			if (details[0].equals("00")){ //end
				
			}
	
			else if (details[0].equals("01")){ //withdrawal
							
			}
			
			else if (details[0].equals("02")){ //transfer
				
			}
			
			else if (details[0].equals("03")){ //paybill
				
			}
			
			else if (details[0].equals("04")){ //deposit
				
			}
			
			else if (details[0].equals("05")){ //create
				
			}
			
			else if (details[0].equals("06")){ //delete
				
			}
			
			else if (details[0].equals("07")){ //disable
				
			}
			
			else if (details[0].equals("08")){ //changeplan
				
			}
			
			else if (details[0].equals("09")){ //enable
				
			}
			
			else if (details[0].equals("10")){ //login
				
			}
			
			else{
				System.out.println("Transaction code invalid");
			}
			
			if (!Utilities.CheckForError(test, current_accounts,true)){
				//if valid, then replace current account with test (with transactions applied) 
				current_account = test;
				Fee(current_account);
			}
		}
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
		
		//testing in eclipse
		master_account_file = "E:\\Users\\James\\workspace\\Part 5\\src\\phase4\\MasterAccountsFile.txt";
		transaction_files_folder = "E:\\Users\\James\\workspace\\Part 5\\src\\phase4\\transaction folder";
		
		//calls method to merge transaction files into MergedTransactionFile
		String merged_transaction_filename=Utilities.MergeTransactionFiles(transaction_files_folder);
		List<Account> accounts = Utilities.LoadAccountInformation(master_account_file);
		String[] transactions = Utilities.LoadTransactions(merged_transaction_filename);
		ValidateTransactions(accounts,new ArrayList<Account>(),transactions);
	}
}