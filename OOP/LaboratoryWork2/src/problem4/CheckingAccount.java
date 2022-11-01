package problem4;

public class CheckingAccount  extends Account{

	public double sumPercent;
	protected final double percentOfTransactions = 0.02;
	
	
	public CheckingAccount(int accNumber) {
		super(accNumber);
	}
	
	
	public void transfer(double amount, Account other) {
		super.withdraw(amount);
		other.deposit(amount);
		sumPercent = amount * percentOfTransactions;
		super.withdraw(sumPercent);
	}
	
	public void deductFee() {
		super.withdraw(sumPercent);
	}
	
	public double getSumPercent() {
		return sumPercent;
	}

	public String toString() {
		return super.toString() + ", sumPercent = " + sumPercent + ", Checking Account";
	}
	
}
