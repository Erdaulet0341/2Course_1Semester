package Pr1_code;
import java.util.Scanner;

public class Task5 {
	void Task_5() {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter current balance ");
		int first = in.nextInt();
		System.out.print("Enter persentage ");
		int per = in.nextInt();
		int res;
		res = first + (first*per/100);
		System.out.print("New balance =" + res);
	}
}
