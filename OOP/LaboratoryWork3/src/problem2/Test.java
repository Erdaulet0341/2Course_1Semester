package problem2;


public class Test {
	public static void main(String [] args) {
		Plane p = new Plane("Scat");
		Ship s = new Ship("Titanic");
		
		p.moveable();
		p.moveableAir();
		
		s.moveable();
		s.moveableWater();
	}
}
