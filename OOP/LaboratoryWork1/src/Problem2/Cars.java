package Problem2;

import java.util.Vector;

public class Cars {
	String name;
	Transmissions transmissions;
	private int id;
	private int year;
	final String MATERIAL  = "IRON";
	private String color;
	static Vector<Cars> cars;
	static int cnt;
	
	static{
		cars = new Vector<Cars>();
	}
	{
		id = cnt++;   //initialization block
		cars.add(this);
	}
	
	public Cars() {}
	
	public Cars(String name, int year, String colar){
		this.name = name;
		this.year = year;
		this.color = colar;
	}
	
	public void setName(String name) {
		this.name= name;
	}
	public void setColor(String color) {
		this.color= color;;
	}
	public Cars(String name, int year, String color, Transmissions transmissions)
	{
		this(name, year, color);
		this.transmissions = transmissions;
	}
	
	public void Edit(String color) {
		this.color = color;
	}
															//overloading
	public void Edit(Transmissions transmissions) {
		this.transmissions = transmissions;
	}
	public void Edit(int cnt) {
		this.cnt = cnt;
	}
	
	public String getColor() {
		return color;
	}
	
	public String getName() {				//read only fields
		return name;
	}
	
	public int getId() {
		return id;
	}
	
	public String toString() {
		return "Car "+ name+ ", "+ id + ", "+year + ", "+color + ", "+transmissions + ".";
	}
	
	
}
