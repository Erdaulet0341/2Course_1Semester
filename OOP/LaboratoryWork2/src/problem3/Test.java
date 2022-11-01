package problem3;

import java.util.Scanner;
import java.util.Vector;

public class Test {

	public static void main(String[] args) {
		System.out.println("Hello, enter your current position and the position you want to go:");
		System.out.print("Current: ");
		Scanner in = new Scanner(System.in);
		String current ="";
		
		while(current!="exit") {
			System.out.print("Current(exit=end): ");
			current = in.next();
			if(current.equals("exit")) {
				System.out.println("The end!!!");
				System.exit(0);
			}
			System.out.print("Position you want to go: ");
			String newPos = in.next();
			Position a = new Position(current);
			Position b = new Position(newPos);
			
			Piece rock = new Rock();
			Piece king = new King();
			Piece bishop = new Bishop();
			
			Vector<Piece> v = new Vector<Piece>();
			v.add(rock);
			v.add(king);
			v.add(bishop);
			
			for(Piece i:v) {
				i.setPosition(a, b);
				System.out.println(i);
			}
			System.out.println("\n");
		}
	}

}
