package problem1;

public class Test {
	public static void main(String[] args) {
		Plane plane = new Plane("Scat"); 
		Ship ship = new Ship("Titanic");
		
//		Transport t = new Transport("transport");  // with abstract classes and interfaces we don't use new() key-word      
//		Moveable m = new Moveable();
		
		plane.move();
		ship.drownAble();
		ship.moveable(ship);
		
		//System.out.println(plane);
	}
}
