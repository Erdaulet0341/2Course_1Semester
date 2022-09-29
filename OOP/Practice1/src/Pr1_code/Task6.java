package Pr1_code;

public class Task6 {
	void Task_6(String word) {
		int n = word.length()-1;
		for (int i=0; i<word.length(); i++) {
			char c = word.charAt(i);
			//System.out.println("c = " + c);
			char k = word.charAt(n);
			//System.out.println("k = " + k);
			if (c != k) {
				System.out.print("Not palindrome");
				System.exit(0);
			}
			n--;
		}
		System.out.print("Palindrome");
	}
	
}
