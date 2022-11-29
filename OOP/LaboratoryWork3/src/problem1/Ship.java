package problem1;

public class Ship extends Transport implements Moveable, DrownAble { // can implement one or more interfaces  (interface)
	public Ship() {};
	public Ship(String name) {
		super(name);
	}

	@Override
	public void moveable(Transport t) {
		System.out.println(t.getName() + " is moving !!!");
		
	}

	@Override
	public void move() {
		System.out.println("Ship is moving !!!");
	}

	@Override
	public void drownAble() {
		System.out.println("Ship can drown on water !!!");
		
	}
	
	public String toString() {
		return "Name = " + super.getName();
	}
	
}
