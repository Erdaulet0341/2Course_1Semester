package problem2;

public class Ship implements Moveable, MoveableOnWater{
	public String name;
	public Ship() {};
	public Ship(String name) {
		this.name = name;
	}
	public void moveable() {
		System.out.println("Ship is moving");
	}
	public void moveableWater() {
		System.out.println("Ship can move on water");
	}
}
