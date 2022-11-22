package problem1;

public class Test {
	public static void main(String[] args) {
		Plane plane = new Plane("Scat"); 
		Ship ship = new Ship("Titanic");
		
		plane.move();
		
		ship.drownAble();
		ship.moveable(ship);
		System.out.println(ship.isDrown); 
	}
}
