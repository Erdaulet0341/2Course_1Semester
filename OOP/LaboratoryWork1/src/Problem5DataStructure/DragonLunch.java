package Problem5DataStructure;
import java.util.LinkedList;

public class DragonLunch {
	public String s = "";
	public int cnt = 0;
	String kidnap() {
		for(Person i: Person.person) {
			if(i.gender == Gender.B) {
				s+="B";
			}
			else {
				s+="G";
			}
		}
		return s;
	
	}
	boolean WillDragonEatOrNot(){
		LinkedList<Character> linky = new LinkedList<>();
		DragonLunch d = new DragonLunch();
		String s1 = d.kidnap();
		for (int i=0; i<s1.length(); i++) { //GBGB
			if(linky.isEmpty()) {
				linky.addLast(s1.charAt(i));
			}
			else if(linky.getLast() == 'B' && s1.charAt(i) == 'G') {
				linky.removeLast();
			}
			else {
				linky.addLast(s1.charAt(i));
			}
		}
		this.cnt = linky.size();
		if(linky.isEmpty()) return true;
		else return false;
	}

	
	String getString() {
		return s;
	}
}
