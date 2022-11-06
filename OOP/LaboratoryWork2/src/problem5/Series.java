package problem5;

public class Series extends Circuit{
	private double res1;
	private double res2;
	double potDiff;
	
	public Series() {
		
	}

	public Series(Circuit a, Circuit b) {
		this.res1 = a.getResistance();
		this.res2 = b.getResistance();
	}

	
	public double getRes1() {
		return res1;
	}

	public void setRes1(double res1) {
		this.res1 = res1;
	}

	public double getRes2() {
		return res2;
	}

	public void setRes2(double res2) {
		this.res2 = res2;
	}
	
	public double getResistance() {
		return res1+res2;
	}

	public double getPotentialDiff() {
		return potDiff;
	}

	public void applyPotentialDiff(double V) {
		this.potDiff = V;
	}	
	

	public String toString() {
		return super.toString() + " Series [Resistance=" + getResistance() + ", PotentialDiff=" + getPotentialDiff() + "]";
	}
}
