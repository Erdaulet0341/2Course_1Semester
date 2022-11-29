package problem4;
import java.text.ParseException;
import java.util.Collections;


public class Test {
	public static void main(String[] args) throws CloneNotSupportedException, ParseException{
		
		Dates date = new Dates();
		
		Employee p1 = new Employee("Era", 984000.5, date.getTime("30-01-2016"), "KZ_01" );
		Employee p2 = new Employee("Saule", 783000.5, date.getTime("15-05-2010"), "KZ_02" );
		Employee p3 = new Employee("Aset", 899400.5, date.getTime("27-04-2010"), "KZ_03" );
		

		Manager m1 = new Manager("Kris",1206000 ,Employee.employees);
		Employee.employees.remove(m1);
		m1.cnt--;
		
		Employee p4 = new Employee("Arman", 569400.5, date.getTime("19-03-2013"), "KZ_04");

		Manager m2 = new Manager("Tom",1356000, Employee.employees);
		Employee.employees.remove(m2);
		m2.cnt--;
		
		System.out.println(m1);
		System.out.println(m2);
		System.out.println("\n");
		
		if(m1.compareTo(m2) == 0) System.out.println("Equal");
		else if (m1.compareTo(m2) == 1) System.out.println(m1.getName() + " more than " + m2.getName());
		else System.out.println(m1.getName() + " less than " + m2.getName());
		
		
		Collections.sort(Employee.employees); // default (sort by salary)
		System.out.println("\nSort by Salary:");
		for(Employee i: Employee.employees) {
			System.out.println(i);
		}


		Collections.sort(Employee.employees, new SortByName()); // sort by Name
		
		System.out.println("\nSort by Name:");
		for(Employee i: Employee.employees) {
			System.out.println(i);
		}
		
		Collections.sort(Employee.employees, new SortByHireDate()); // sort by Date
		
		System.out.println("\nSort by Date:");
		for(Employee i: Employee.employees) {
			System.out.println(i);
		};
		
		
		Employee cloneP4;
		cloneP4 = (Employee) p4.clone();
		System.out.println("\np4 = " + p4);
		System.out.println("cloneP4 ="  + cloneP4);

		Manager cloneM1 ;
		cloneM1 = (Manager) m1.clone();
		System.out.println("\nm1 = " + m1);
		System.out.println("cloneM1 = "  + cloneM1);
		
	}
}
