package problem1;

public class Cube extends Shape {
	private double lenght;
	
	public Cube() {
		
	}
	public Cube(double lenght) {
		super();
		this.lenght = lenght;
	}
	
	public void setLenght(double lenght) {
		this.lenght = lenght;
	}
	
	public double volume() {
		return lenght*lenght*lenght;
	}
	public double surfaceArea() {
		return 6*lenght*lenght;
	}
	
	public double getVolume() {
		return volume();
	}
	public double getSurfaceArea(){
		return surfaceArea();
	}
	public double getLenght() {
		return lenght;
	}
	
	public String toString() {
		return super.toString() + ", lenght = "+lenght;
	}
}
