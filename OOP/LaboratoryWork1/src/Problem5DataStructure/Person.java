package Problem5DataStructure;

import java.util.Vector;

public class Person {
	Gender gender;
	String name;
	public static Vector<Person> person;
	static{
	person = new Vector<Person>();
	}
	
	{
		person.add(this);
	}
	
	public Person(String name){
		this.name = name;
	}
	public Person(String name, Gender gender){
		this.name = name;
		this.gender = gender;
	}
	public String toString() {
		return "Name = "  + name + ", gender = " + gender;
	}
}
