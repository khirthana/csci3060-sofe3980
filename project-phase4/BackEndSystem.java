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
	ERROR <msg = type & description of error & file caused error>
	-if bad input file format, it should immediately stop and log a fatal error on the terminal
	*/
	
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
		String Merged_transaction_filename=Utilities.MergeTransactionFiles(transaction_files_folder);
	}
}