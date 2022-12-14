package Problem4;
import Pr2_code.Student;
import Pr2_code.Student.*;
import java.util.LinkedList;

public class GradeBook{
	Course course = new Course();
	double average;
	double lowest=1e9;;
	double highest;
	static double sumOfGrades;
	static int sumOfStudents=0;
	String nameOfHighest, nameOfLowest; int idOfHighest, idOfLowest;
	
	public String displayMassege() {
		return "Welcome to the grade book for CS101 Object-oriented Programming and Desing!"
				+ "\n\n" + "Please, input greades for students: " + "\n\n";
	}
	
	public double getAverage() {
		for(Student s: Student.students) {
			int grade = s.getGrade();
			sumOfGrades+=grade;
			sumOfStudents++;
			if(grade < lowest) {
				lowest = s.getGrade();
				idOfLowest = s.getId();	
				nameOfLowest = s.getName();
			}
			if(grade>highest) {
				highest = s.getGrade();
				idOfHighest = s.getId();	
				nameOfHighest = s.getName();
				}
		}
		average = sumOfGrades/sumOfStudents;
		return average;
	}
	
	public double getHighest() {
		return highest;
	}
	public double getLowest() {
		return lowest;
	}
	public String toString() {
		return "course = " + course.name + ",number of credits = "+ course.getNumberOfCredits() +
				", average = " + average;
	}
	
	public String determineClassAverage() {
		return "\n"+"Class average is " + average + ". Lowest grade is " + lowest + 
				" (Student " + nameOfLowest + ", id: " + idOfLowest + ").\n"
				+ "Heghest grade is " + highest + 
				" (Student " + nameOfHighest + ", id: " + idOfHighest + ").\n";
	}
	
	public static int[] countGrade() {
		int arr[];
		arr = new int[11];
		for (int i=0; i<11; i++) {
			arr[i] = 0;
		}
		for(Student s: Student.students) {
			int grade = s.getGrade();
			if (grade<=9) arr[0]++;
			if(10<=grade && grade<=19) arr[1]++;
			if(20<=grade && grade<=29) arr[2]++;
			if(30<=grade && grade<=39) arr[3]++;
			if(40<=grade && grade<=49) arr[4]++;
			if(50<=grade && grade<=59) arr[5]++;
			if(60<=grade && grade<=69) arr[6]++;
			if(70<=grade && grade<=79) arr[7]++;
			if(80<=grade && grade<=89) arr[8]++;
			if(90<=grade && grade<=99) arr[9]++;
			if(grade ==100) arr[10]++;
		}
		return arr;
	}
	
	public void outputBarChart() {
		int arr[] = countGrade();
		System.out.print("Grades distribution:\n");
		System.out.print("00-09: ");
		for (int i=0; i<arr[0]; i++) System.out.print("*");
		System.out.print("\n"+"10-19: ");
		for (int i=0; i<arr[1]; i++) System.out.print("*");
		System.out.print("\n"+"10-29");
		for (int i=0; i<arr[2]; i++) System.out.print("*");
		System.out.print("\n"+"30-39: ");
		for (int i=0; i<arr[3]; i++) System.out.print("*");
		System.out.print("\n"+"40-49: ");
		for (int i=0; i<arr[4]; i++) System.out.print("*");
		System.out.print("\n"+"50-59: ");
		for (int i=0; i<arr[5]; i++) System.out.print("*");
		System.out.print("\n"+"60-69: ");
		for (int i=0; i<arr[6]; i++) System.out.print("*");
		System.out.print("\n"+"70-79: ");
		for (int i=0; i<arr[7]; i++) System.out.print("*");
		System.out.print("\n"+"80-89: ");
		for (int i=0; i<arr[8]; i++) System.out.print("*");
		System.out.print("\n"+"90-99: ");
		for (int i=0; i<arr[9]; i++) System.out.print("*");
		System.out.print("\n"+"100: ");
		for (int i=0; i<arr[10]; i++) System.out.print("*");
	}
}