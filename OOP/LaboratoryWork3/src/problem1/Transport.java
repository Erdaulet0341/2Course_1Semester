package problem1;

public abstract class Transport{ 
	private String name; //can have final, non-final, static and non-static fields
	
	public Transport() {}; // can have constructors
	
	public Transport(String name) {
		this.name = name;
	}
	
	
	public abstract void move();
	
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public String toString() {
		return "Name = " + name;
	}
	
}
