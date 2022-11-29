package problem1;

public class Plane extends Transport implements Moveable{ // extend only one abstract class (abstract)
	public Plane() {};
	public Plane(String name) {
		super(name);
	}

	@Override
	public void move() {
		System.out.println("Plane is moving !!!");
		
	}
	@Override
	public void moveable(Transport t) {
		System.out.println("Plane is moving !!!");	
	}
	
	public String toString() {
		return "Name = " + super.getName();
	}
}
