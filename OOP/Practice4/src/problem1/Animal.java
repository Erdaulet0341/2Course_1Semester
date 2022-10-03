package problem1;
import java.util.Vector;

public class Animal {
	String name;
	private int age;
	double weight;
	String voice;
	static Vector<Animal> animals;
	static {
		animals = new Vector<Animal>();
	}
	{
		animals.add(this);
	}
	
	
	public Animal() {}
	public Animal(String name) {
		this.name = name;
	}
	
	public Animal(String name, int age, double weight, String voice) {
		this.name = name;
		this.age = age;
		this.weight = weight;
		this.voice = voice;
	}
	public Animal(String name, int age, double weight) {
		this.name = name;
		this.age = age;
		this.weight = weight;
		this.voice = "Voice don't inputed!";
	}
	
	
	String getName() {
		return name;
	}
	
	public String toString() {
		return "Name = " + name + ", age =" + age + ", weight = " + weight + ", voice = " + voice + "\n";
	}
	
}
