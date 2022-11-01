package problem5;

public abstract class Circuit {
	public abstract double getResistance();
	public abstract double getPotentialDiff();
	public abstract void applyPotentialDiff(double V);
	
	public double getPower() {
		return getCurrent() * getPotentialDiff();	
	}
	
	public double getCurrent() {
		return getResistance() / getPotentialDiff();
	}
	
	public String toString() {
		return "Circuit [Power=" + getPower() + ", Current=" + getCurrent() + "]";
	}
}