package problem1;

public class Cylinder extends Shape {
	private double radius;
	private double height;
	
	public Cylinder() {
		
	}
	
	public Cylinder(double radius, double height) {
		super();
		this.radius = radius;
		this.height = height;
	}
	
	public void setHeight(double height) {
		this.height = height;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public double volume() {
		return PI*radius*radius*height;
	}
	
	public double surfaceArea() {
		return 2*PI*radius*(radius + height);
	}
	
	public double getVolume() {
		return volume();
	}
	public double getSurfaceAres() {
		return surfaceArea();
	}
	
	public double getRadius() {
		return radius;
	}

	public double getHeight() {
		return height;
	}

	public String toString() {
		return super.toString() + ", raduis = " + radius + ", height = " + height;
 	}
}
