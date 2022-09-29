package One;

public class Person {
	public int height = 170;
	public String name;
	
	public void say(String name) {
		System.out.print("Hello, " + name);
	}
	
	public Person() {
		
	}
	
	public Person(String n) {
		name = n;
	}
	
	public Person(int h, String n) {
		height = h;
		name = n;
	}
}
/*
 * Поля - переменные;
 * Методы ө функцияж;
 */