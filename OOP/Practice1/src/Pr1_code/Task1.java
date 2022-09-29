package Pr1_code;

public class Task1 {
	
	void Task_1(String name) {
		System.out.print("+");
		
		for (int i=0; i<name.length(); i++) {
			System.out.print("-");
			
		}
		System.out.print("+" + "\n" + '|' + name + '|' + '\n' + '+');
		for (int i=0; i<name.length(); i++) {
			System.out.print("-");
		}
		
		System.out.print("+");
		
	}
}
