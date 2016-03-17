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
		
		Iterator<Account> it = accounts.iterator();
		  while(it.hasNext())
		  {
			  Account account=(Account) it.next();
			  if( (account.GetAccountName()).equals(name)){
				  return account;
			  }
		  }
		return null;
	}


//method to gather account information associated with input account number
	public static Account GetAccountFromNumber(String number,List<Account> accounts){

		Iterator<Account> it = accounts.iterator();
		  while(it.hasNext())
		  {
			 Account account=(Account) it.next();
			
			  if((account.GetAccountNumber()).equals(number)){
				  return account;
			  }
		  }
		return null;
	}
}
