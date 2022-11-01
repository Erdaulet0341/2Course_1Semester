package problem4;

public class Account {
	private double balance; // the current balance
	private int accNumber; // account number
	
	
	public Account(int accNumber) {
		this.balance = 0.0;
		this.accNumber = accNumber;
	}

	public void withdraw(double sum) {
		balance-=sum;
	}
	
	public void deposit(double sum) {
		balance+=sum;
	}
	
	public double getBalance() {
		return balance;
	}

	public int getAccNumber() {
		return accNumber;
	}
	
	public void transfer(double amount, Account other) {};

	public String toString() {
		return "Account [balance=" + balance + ", accNumber=" + accNumber + "]";
	};
	
	public final void print() {
		System.out.println(toString());
	}
	
}
