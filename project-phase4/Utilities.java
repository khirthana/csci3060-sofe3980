/*
authors: Khirthana Subramanian - 100453865
         Jaina Patel - 100523188
				 James Morrison - 100524362
This class is meant to contain simplified and modular usages of common functions
 */

package phase4;
import java.io.*;
import java.util.*;

public class Utilities{

//method to merge transaction files into MergedTransactionFile
	public static String MergeTransactionFiles(String transaction_files_folder){
		
		String transaction_file_name="MergedTransactionFile.txt";
		
		FileWriter fstream = null;
		BufferedWriter out = null;
		try {
			fstream = new FileWriter(transaction_file_name, true);
			 out = new BufferedWriter(fstream);
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		File[] files = new File(transaction_files_folder).listFiles();
	
		for (File f : files) {
			FileInputStream fis;
			try {
				fis = new FileInputStream(f);
				BufferedReader in = new BufferedReader(new InputStreamReader(fis));
 
				String aLine;
				while ((aLine = in.readLine()) != null) {
					out.write(aLine);
					out.newLine();
				}
 
				in.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
 
		try {
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
 
		
		 return transaction_file_name;
	}
	
	
	
	/*
	ERROR <msg = type & description of error>
	-no bank account should ever have a negative balance
	-a newly created bank account must have an account number different from all existing bank accounts
	*/
	//method used to report certain errors using standardised format
	public static boolean CheckForError(Account placeholder_account,ArrayList<Account> accounts, boolean old){
		
		if (placeholder_account.GetBalance() < 0){
			System.out.println("ERROR <negative balance issue>");
			return false;
		}
		
		if (!old){
			for (Account a : accounts){
				if (placeholder_account.GetAccountNumber() == a.GetAccountNumber()){
					System.out.println("ERROR <accounts with same number issue>");
					return false;
				}
			}
		}
		return true;
	}
	
//method to load account information from Master Bank Accounts File	
	public static List<Account> LoadAccountInformation(String accounts_file) throws IOException{

	//read through accounts file to get information about account holder
	String line;
	List<Account> accounts =new ArrayList<Account>();
	BufferedReader br = new BufferedReader(new FileReader(accounts_file));

	while ((line = br.readLine()) != null) {
		if (line.length() == 39){
		Account account=new Account(line.substring(0,5),line.substring(6,26),line.substring(27,28),line.substring(29,37),line.substring(38,39));
		accounts.add(account);
		}
	}
	br.close();

	return accounts;
	}


	
//method to gather account information associated with input account name
	public static Account GetAccountFromName(String name, List<Account> accounts){
		for (int n = 0; n < accounts.size();n++){
			if (accounts.get(n).GetAccountName().equals(name)){
				return accounts.get(n);
			}
		}
		return null;
	}


//method to gather account information associated with input account number
	public static Account GetAccountFromNumber(String number,List<Account> accounts){
		for (int n = 0; n < accounts.size();n++){
			if (accounts.get(n).GetAccountNumber().equals(number)){
				return accounts.get(n);
			}
		}
		return null;
	}
}


