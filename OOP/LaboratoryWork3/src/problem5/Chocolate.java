package problem5;

public class Chocolate implements Comparable<Chocolate>{
	private String name;
	private int weight;
	
	public Chocolate() {};
	
	public Chocolate(String name, int weight) {
		this.name = name;
		this.weight = weight;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getWeight() {
		return weight;
	}
	public void setWeight(int weight) {
		this.weight = weight;
	}

	
	public String toString() {
		return "Chocolate [name=" + name + ", weight=" + weight + "]";
	}

	@Override
	public int compareTo(Chocolate o) {
		return weight - o.weight;
	}
	
	
}
