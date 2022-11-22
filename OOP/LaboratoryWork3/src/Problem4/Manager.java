package Problem4;
import java.util.Comparator;
import java.util.Objects;
import java.util.Vector;


public class Manager extends Employee implements Comparable<Employee>{
	final int bonusForOneEmployee=5;
	public int cnt=0;
	Employee e;
	Vector<Employee> v;
	public Manager() {};
	
	public Manager(String name, double salary,  Vector<Employee> v) {
		super(name, salary);
		this.v = v;
		cnt = v.size();
	};
	
	public int getBonus() {
		return bonusForOneEmployee*cnt;
	}
	
	
	public int hashCode() {
		return Objects.hash(getBonus());
	}
	
	
	public boolean equals(Object obj) {
		if(!super.equals(obj)) return false;
		Manager m = (Manager) obj;
		return getBonus() == m.getBonus();
	}
	
	public int compareTo(Manager m) {
		if(m.getBonus() == getBonus()) return 0;
		else if(getBonus() > m.getBonus()) return 1;
		return -1;
	}
	
	public String toString() {
		return"Manager name = " + super.getName() + ", salary = " + super.getSalary() + ", bonus=" + getBonus();
	}
}
