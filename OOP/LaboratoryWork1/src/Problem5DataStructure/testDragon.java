package Problem5DataStructure;
import java.util.Scanner;

public class testDragon {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		DragonLunch dragonLunch = new DragonLunch();
		boolean checkEnd= true;
		while(checkEnd) {
			String name = in.next();
			if (name.equals("End!")) {
				checkEnd = false;
			}
			else {
				char gender = in.next().charAt(0);
				if (gender == 'B') {
					Person p = new Person(name, Gender.B);
				}
				else {
					Person p = new Person(name, Gender.G);
				}
			}
		}
		if (dragonLunch.WillDragonEatOrNot()) {
			System.out.println("Dragon don't eat students!"
					+ "");
		}
		else {
			System.out.println("Dragon eat "+dragonLunch.cnt + " students!");
		}
	}
}
/*
Asem G
Era B
Asel G
Duka B
End!

Asem B
Era B
Asel G
Duka G
End!
 **/
