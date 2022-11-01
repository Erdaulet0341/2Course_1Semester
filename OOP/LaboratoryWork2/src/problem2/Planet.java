package problem2;

import java.util.Objects;

public abstract class Planet {
	protected double mass;
	protected double radius;
	final double G = 6.6743*10e-10; //universal gravitational constant
	Atmosphere atm;
	
	public Planet() {
		
	}
	
	public Planet(double mass, double radius, Atmosphere atm) {
		this.mass = mass;
		this.radius = radius;
		this.atm = atm;
	}

	public Planet(double mass, double radius) {
		this.mass = mass;
		this.radius = radius;
	}

	public double getMass() {
		return mass;
	}

	public void setMass(double mass) {
		this.mass = mass;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public abstract String facts();
	
	final double findGravity() {
		return (G*mass)/(radius*radius);
	}
	
	public double getGravity(){
		return findGravity();
	}
	public String getFacts() {
		return facts();
	}
	
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Planet p = (Planet) obj;
		return atm == p.atm && mass == p.mass && radius == p.radius;
	}
	public int hashCode() {
		return Objects.hash(atm, mass, radius);
	}


	public String toString() {
		return "Planet [mass=" + mass + ", radius=" + radius + ", facts:" + facts() + ", Gravity=" + findGravity() + "]";
	}	
	
}

