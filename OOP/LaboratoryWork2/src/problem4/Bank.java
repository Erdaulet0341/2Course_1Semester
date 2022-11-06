package problem4;
import java.util.Scanner;
import java.util.Vector;

public class Bank {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Account a1 = new Account(1);
		Account a2 = new Account(2);
		Account a3 = new Account(3);
		Account c1 = new CheckingAccount(4);
		Account c2 = new CheckingAccount(5);
		Account c3 = new CheckingAccount(6);
		Account s1 = new SavingAccount(7);
		Account s2 = new SavingAccount(8);
		Account s3 = new SavingAccount(9);
		
		System.out.println("\n Banking System Application \n"); 
		int ch;  
        do {  
        	Vector<Account> accounts = new Vector<Account>();
    		accounts.add(a1); accounts.add(a2); accounts.add(a3);
    		accounts.add(c1); accounts.add(c2); accounts.add(c3);
    		accounts.add(s1); accounts.add(s2); accounts.add(s3);
            System.out.println("1. Display all account details \n2. Search by Account number\n3. Deposit the amount \n"
            		+ "4. Withdraw the amount \n5. Transfer to another account \n6. Exit ");  
            System.out.println("Enter your choice: ");  
            ch = in.nextInt();  
                switch (ch) {  
                    case 1:  
                        for (Account i: accounts) {  
                            System.out.println(i); 
                        }  
                        break;  
                    case 2:  
                        System.out.print("Enter account number you want to search: ");  
                        int ac_no = in.nextInt();  
                        boolean found = false;  
                        for (Account i: accounts) {  
                            if(i.getAccNumber() == ac_no) {
                            	System.out.println(i);
                            	found = true;
                            }
                        }
                        if (!found) {  
                            System.out.println("Search failed! Account doesn't exist..!!");  
                        }  
                        break;  
                    case 3:  
                        System.out.print("Enter Account number: ");  
                        ac_no = in.nextInt();  
                        System.out.print("Enter amount sum: ");
                        int amn = in.nextInt();
                        found = false;  
                        for (Account i: accounts) {  
                            if(i.getAccNumber() == ac_no) {
                            	i.deposit(amn);
                            	found = true;
                            }
                        }  
                        if (!found) {  
                            System.out.println("Search failed! Account doesn't exist..!!");  
                        }  
                        break;  
                    case 4:  
                        System.out.print("Enter Account Number: ");  
                        ac_no = in.nextInt(); 
                        System.out.print("Enter amount sum: ");
                        amn = in.nextInt();
                        found = false;  
                        for (Account i: accounts) {  
                            if(i.getAccNumber() == ac_no) {
                            	if (i.getBalance()<amn) {
                            		System.out.println("In your balance not enought money, operarion failed..!!");
                            		found = true;
                            		break;
                            	}
                            	else {
	                            	i.withdraw(amn);
	                            	found = true;
                            	}
                            }
                        }  
                        if (!found) {  
                            System.out.println("Search failed! Account doesn't exist..!!");  
                        }  
                        break;  
                    case 5:  
                    	System.out.print("Enter Account Your Number : ");  
                        ac_no = in.nextInt(); 
                        System.out.print("Enter amount sum: ");
                        amn = in.nextInt();
                        System.out.print("Enter Account Number do you want transfer: ");  
                        int  ac_no2 = in.nextInt(); 
                        found = false;  
                        if(ac_no == 4 || ac_no == 5 || ac_no == 6) {
                        	for (Account i: accounts) {  
                                if(i.getAccNumber() == ac_no) {
                                    for (Account j: accounts) {  
                                        if(j.getAccNumber() == ac_no2) {
                                        	i.transfer(amn, j);
                                        	found = true;
                                        }
                                    } 
                                }
                            }  
                            if (!found) {  
                                System.out.println("Search failed! Account doesn't exist..!!");  
                            } 
                        }
                        else System.out.println("Invalid Account number..!!");
                        break; 
                    case 6:  
                        System.out.println("Goodbye!!!");  
                        break;  
                }  
                System.out.println("\n");
            }  
            while (ch != 6);  
		
		
	}
}
