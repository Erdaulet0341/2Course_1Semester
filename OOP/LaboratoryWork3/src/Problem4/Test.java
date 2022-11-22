package Problem4;
import java.util.Collections;
import java.util.Date;

public class Test {
	public static void main(String[] args) throws CloneNotSupportedException{
		Employee p1 = new Employee("Era", 984000.5, new Date(119, 7, 30), "KZ_01" );
		Employee p2 = new Employee("Duka", 783000.5, new Date(121, 5, 17), "KZ_02" );
		Employee p3 = new Employee("Aset", 899400.5, new Date(120, 1, 3), "KZ_03" );
		
		Collections.sort(Employee.employees);
		
		for(Employee i: Employee.employees) {
			System.out.println(i);
		}
		System.out.println("\n");
		
		Employee p4 = new Employee("Arman", 569400.5, new Date(115, 10, 29), "KZ_04");
		
		
		Manager m1 = new Manager("Kris",1206000 ,Employee.employees);
		Employee.employees.remove(m1);
		m1.cnt--;
		
		
		for(Employee i: Employee.employees) {
			System.out.println(i);
		}
		System.out.println("\n");
		
		Manager m2 = new Manager("Tom",1356000, Employee.employees);
		Employee.employees.remove(m2);
		
		System.out.println(m1);
		System.out.println(m2);
		System.out.println("\n");
		
		if(m1.compareTo(m2) == 0) System.out.println("Equal");
		else if (m1.compareTo(m2) == 1) System.out.println(m1.getName() + " more than " + m2.getName());
		else System.out.println(m1.getName() + " less than " + m2.getName());
		System.out.println("\n");
		
		System.out.println("\n");
		
		Collections.sort(Employee.employees, new SortByName());
		
		for(Employee i: Employee.employees) {
			System.out.println(i);
		}
		
		System.out.println("\n");
		
		Collections.sort(Employee.employees, new SortByHireDate());
		
		for(Employee i: Employee.employees) {
			System.out.println(i);
		}
		System.out.println("\n");
		
		Employee cloneP4;
		cloneP4 = (Employee) p4.clone();
		
		System.out.println("p4 = " + p4);
		System.out.println("cloneP4 ="  + cloneP4);

	}
}
