package Pr1_code;
import java.util.Scanner;
import java.lang.Math;

public class Task4 {
	void Task_4() {
		Scanner in = new Scanner(System.in);
		System.out.print("a = ");
		int a = in.nextInt();
		System.out.print("b = ");
		int b = in.nextInt();
		System.out.print("c = ");
		int c = in.nextInt();
		
		double D = b*b - 4*a*c;
		System.out.println(Math.sqrt(D));
		
		if (D<0) {
			System.out.println("ERROR");
		}
		else if (D == 0) {
			int x = -(int) b/2*a;
			System.out.println("x = " + x);
		 }
		else {
			double x1 = (-b- Math.sqrt(D))/(2*a);
			double x2 =  (-b+ Math.sqrt(D))/(2*a);
			System.out.println("x1 = " + x1);
			System.out.println("x2 = " + x2);
		}
	}
}
