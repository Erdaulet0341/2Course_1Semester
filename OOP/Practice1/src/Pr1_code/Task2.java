package Pr1_code;
import java.util.Scanner;
import java.lang.Math;

public class Task2 {
	void Task_2() {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int perimeter = n*4;
		System.out.println("Perimeter = " + perimeter);
		int area = n*n;
		System.out.println("Area = " + area);
		int diagonal = (int) (n*(Math.sqrt(2)));
		System.out.println("Diagonal = " + diagonal);
	}
}
