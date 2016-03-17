/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362

This class accepts MasterAccountsFile and transaction files folder from command line;
calls method to merge transaction files into MergedTransactionFile
*/

package phase4;
import java.io.*;
import java.util.*;

public class main{
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
