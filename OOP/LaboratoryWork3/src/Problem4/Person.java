package Problem4;

import java.util.Objects;

public abstract class Person {
	private String name;
	public Person() {};
	public Person(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	
	public int hashCode() {
		return Objects.hash(name);
	}
	
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Person p = (Person) obj;
		return name == p.name;
	}
	
	public String toString() {
		return "Person [name=" + name + "], ";
	}
	
	
}
