package problem1;

public class Sphere extends Shape{
	private double radius;
	
	public Sphere() {
		
	}
	
	public Sphere(double radius) {
		this.radius = radius;
	}
	
	public double volume() {
		double r3 = radius*radius*radius;
		return ((double)4/3)*PI*r3;
	}
	
	public double surfaceArea() {
		return 4*PI*radius*radius;
	}
	
	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	public String toString() {
		return super.toString() + ", raduis = " + radius;
	}
}
