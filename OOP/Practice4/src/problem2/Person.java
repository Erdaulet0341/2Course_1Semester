package problem2;
import java.util.Vector;

public class Person {
	String name;
	String address;
	static Vector<Person> persons;
	static{
		persons = new Vector<Person>();
	}
	{
		persons.add(this);
	}
	
	public Person() {}
	
	public Person(String name, String address) {
		this.name = name;
		this.address = address;
	}
	
	String getName() {
		return name;
	}
	String getAddress() {
		return address;
	}
	
	void setAddress(String address) {
		this.address = address;
	}
	
	public String toString() {
		return "[Person [name = " + name + ", address = " + address + "]";
	}
}
