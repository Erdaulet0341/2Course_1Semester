package problem1;

public class Horse extends Animal {
	double speed;
	
	public Horse() {}
	
	
	
	public Horse(String name, int age, double weight, String voice, double speed) {
		super(name, age, weight, voice);
		this.speed = speed;
	}
	public Horse(String name, int age, double weight, double speed) {
		super(name, age, weight);
		this.speed = speed;
	}
	public Horse(String name, double speed) {
		super(name);
		this.speed = speed;
	}
	
	double getSpeed() {
		return speed;
	}
	String getName() {
		return name;      //Overriding
	}
	
	public double change(double weight) {
		super.weight = weight;
		return  super.weight;
	}											         //Overloading
	public double change() {
		return 0;
	}
	public String toString() {
		return "Name = " + name + ", speed = " + speed;  //Overriding
	}
	
}
