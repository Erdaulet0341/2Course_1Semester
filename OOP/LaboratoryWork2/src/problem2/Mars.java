package problem2;

import java.util.Objects;

public class Mars extends Planet{
	int numberOfProbes;
	
	public Mars() {
		
	}
	public Mars(double mass, double radius, Atmosphere atm, int numberOfProbes) {
		super(mass, radius, atm);
		this.numberOfProbes = numberOfProbes;
	}
	public Mars(double mass, double radius) {
		super(mass, radius);
	}

	public String facts() {
		return "Red planet, has water, has 2 moons";
	}
	
	public boolean equals(Object obj) {
		if(!super.equals(obj)) return false;
		Mars m = (Mars)obj;
		return numberOfProbes == m.numberOfProbes;
	}
	public int hashCode() {
		return Objects.hash(atm, mass, radius, numberOfProbes);
	}
	
	public String toString() {
		return super.toString() + " Mars [numberOfProbes=" + numberOfProbes + "]";
	}	
}
