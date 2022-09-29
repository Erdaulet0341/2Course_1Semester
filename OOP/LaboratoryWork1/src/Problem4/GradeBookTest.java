package Problem4;
import java.util.Scanner;

import Pr2_code.Student;
import Pr2_code.Student.*;

public class GradeBookTest {
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		GradeBook gradeBook = new GradeBook();
		Course course = new Course("OOP", 5);
		System.out.print(gradeBook.displayMassege());
		
		boolean checkEnd = true;;
		int cnt = 0, grade=0;
		while(checkEnd) {
			if(grade != -1) {
				char c = (char) ('A'+cnt);
				System.out.print("Student  " + c + ":  ");
				String name = String.valueOf(c);
				grade = in.nextInt();
				if(grade != -1) {
					Student s = new Student(name, grade);
				}
				
			}
			else {
				checkEnd = false;
				break;
				
			}
			cnt++;
		}
		gradeBook.getAverage();
		System.out.println(gradeBook.determineClassAverage());
		gradeBook.outputBarChart();

	}

}
