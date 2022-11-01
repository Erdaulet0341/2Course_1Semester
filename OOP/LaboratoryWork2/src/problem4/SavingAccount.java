package problem4; // deposit

public class SavingAccount extends Account {

	protected final double interestRate = 0.15d;
	
	public SavingAccount(int accNumber) {
		super(accNumber);
	}
	
	public double YearInterestRate() {
		double bal = super.getBalance();
		return bal*interestRate;
	}
	
	public String toString() {
		return super.toString() + ", Year inretest rate = " + YearInterestRate() + ", Saving Accnount";
	}
}
