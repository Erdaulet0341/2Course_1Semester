package Problem1;

import java.util.Scanner;

public class Analyzer {

	public static void main(String[] args) {
		Data data = new Data();
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter number (Q to quit): ");
		String firstString = in.next();
		if(firstString.equals("Q")) {
			System.out.println("Average = "+data.getAverage());
			System.out.println("Maximum = "+data.getMaximum());
		}
		else {
			int number1 = Integer.valueOf(firstString);
			data.setNumber(number1);
			
			while(firstString != "Q") {
				System.out.print("Enter number (Q to quit): ");
				String secondString = in.next();
				if(secondString.equals("Q")) {
					firstString = "Q";
				}
				else {
					int number2 = Integer.valueOf(secondString);
					data.setNumber(number2);
				}
			}
			
			System.out.println("Average = "+data.getAverage());
			System.out.println("Maximum = "+data.getMaximum());
		}
	}

}
