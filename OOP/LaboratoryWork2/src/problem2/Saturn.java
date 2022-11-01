package problem2;

import java.util.Objects;

public class Saturn extends Planet {
	private int rings;
	
	public Saturn() {
		
	}
	public Saturn(double mass, double radius, Atmosphere atm, int rings) {
		super(mass, radius, atm);
		this.rings = rings;
	}
	public Saturn(double mass, double radius, int rings) {
		super(mass, radius);
		this.rings = rings;
	}

	public String facts() {
		return "Strong winds, least dens, has 62 moons"; //
	}
	
	public void setRings(int rings) {
		this.rings = rings;
	}
	public int getRings() {
		return rings;
	}
	

	public boolean equals(Object obj) {
		if(!super.equals(obj)) return false;
		Saturn s = (Saturn) obj;
		return rings == s.rings;
	}
	public int hashCode() {
		return Objects.hash(atm, mass, radius, rings);
	}
	
	public String toString() {
		return super.toString() + " Saturn [rings=" + rings + "]";
	}
	
	
}
