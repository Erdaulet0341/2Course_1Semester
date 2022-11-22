package problem2;

public class Plane implements Moveable, MoveableOnAir{
	public String name;
	public Plane() {};
	public Plane(String name) {
		this.name = name;
	}
	@Override
	public void moveableAir() {
		System.out.println("Plane can move on Air");
		
	}
	@Override
	public void moveable() {
		System.out.println("Plane is moving");
		
	}
	
}
