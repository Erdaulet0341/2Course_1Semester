package problem1;

public class Test {

	public static void main(String[] args) {
		Horse h1 = new Horse("Maximus", 7, 154.6d, "i-ho-ha" ,35);
		Horse h2 = new Horse("Silver", 9, 173.8d, 31);
		Horse h3 = new Horse("Angus", 7, 147.2d, "i-hhh", 29);
		
		for (Animal i: Horse.animals) {
			System.out.println(i);
		}
		System.out.print("h1's name = " + h1.getName());
	}

}
