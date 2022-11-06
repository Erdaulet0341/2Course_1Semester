package problem5;

public class Resistor extends Circuit {
	
	private double resistor;
	private double potentialDifference;
	
	public Resistor() {
		
	}
	public Resistor(double r) {
		this.resistor = r;	}
	
	public double getResistor() {
		return resistor;
	}

	public void setResistor(double resistor) {
		this.resistor = resistor;
	}

	

	public double getResistance() {
		return resistor;
	}


	public double getPotentialDiff() {
		return potentialDifference;
	}

	public void applyPotentialDiff(double V) {
		this.potentialDifference = V;
	}
	
	public String toString() {
		return "Resistor [resistor=" + resistor + ", potentialDifference=" + potentialDifference + "]";
	}
	
}
