package Problem5;

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
		int cntBoys=0;
		DragonLunch d = new DragonLunch();
		String students = d.kidnap();
		for(int i=0; i<students.length(); i++) {
			if(students.charAt(i) == 'B') {
				cntBoys++;
			}
			else {
				if(cntBoys>0) {
					cntBoys--;
				}
				else {
					return false;
				}
			}
		}
		return cntBoys==0;
	}
}
