package problem1;

public abstract class Shape {
	final double PI = 3.14d;
	
	public Shape() {
		
	}
	
	public abstract double volume();
	public abstract double surfaceArea();
	
	public String toString() {
		return "Volume = " + volume() + ", surfaceArea = " + surfaceArea();
	}
}