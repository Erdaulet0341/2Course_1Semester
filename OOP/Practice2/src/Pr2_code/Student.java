package Pr2_code;

import java.util.Vector;


public class Student {
	private int id;
	String name;
	public int year_of_study;
	String faculty;
	static int cnt;
	private int grade;
	public static Vector<Student> students;

	
	static{
		students = new Vector<Student>();
	}
	{
		id = cnt++;
		students.add(this);
	}
	
	
	public Student() {
		
	}

	public Student(String name) {
		this.name = name;
	}
	public Student(String name, int grade) {
		this.name = name;
		this.grade = grade;
	}
	
	public Student(String name, int year_of_study, String faculty, int id) {
		this.year_of_study = year_of_study;
		this.name = name;
		this.faculty = faculty;
		this.id = id;
	}
	
	public int getId() {
		return id;
	}
	public int getGrade() {
		return grade;
	}
	public String getName(){
		return name;
	}
	
	public String toString() {
		return "name = " + name+ ", id = " + id + ", grade = " + grade;
	}
	
	
}
