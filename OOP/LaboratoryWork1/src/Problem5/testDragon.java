package Problem5;
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
		if(dragonLunch.WillDragonEatOrNot()) System.out.print("Dragon DON'T eat students!");
		else System.out.print("Dragon eat students!");
	}
}
/*
Asem G
Era B
Asylzat G
Duka B
End!
GBGB

Duka B
Era B
Asel G
Asylzat G
End!
BBGG
 **/
