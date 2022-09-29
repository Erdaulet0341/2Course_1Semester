package Problem4;

public class Course {
	String name;
	private int numberOfCredits;
	public Course() { }
	
	public Course(String name, int numberOfCredits) {
		this.name = name;
		this.numberOfCredits = numberOfCredits;
	}
	
	public String toString() {
		return "name = " + name + ", numberOfCredits = " + numberOfCredits;
	}
	
	public String getName() {
		return name;
	}
	public int getNumberOfCredits() {
		return numberOfCredits;
	}
}
