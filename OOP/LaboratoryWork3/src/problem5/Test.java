package problem5;
import java.lang.reflect.Array;
import java.util.Date;
import java.util.Vector;
import Pr2_code.Time;
import Problem4.*;

public class Test {

	public static <E> void main(String[] args) {
		Time t = new Time(13, 22 , 16);
		Time t2 = new Time(4, 24, 23);
		Time t3 = new Time(4, 24, 22);
		Time[] times = new Time[3];
        times[0] = t;
        times[1] = t2;
        times[2] = t3;
        //Sort.BubbleSort(times);
        Sort.quicksort(times, 0, times.length-1);
        for(Time i: times) {
        	System.out.println(i);;
        }
		
		System.out.println("\n");
		
		Chocolate c1 = new Chocolate("Snickers", 140);
		Chocolate c2 = new Chocolate("Twix", 130);
		Chocolate c3 = new Chocolate("Mars", 150);
		
		Chocolate[] chocolate  = new Chocolate[3];
		chocolate[0] = c1;
		chocolate[1] = c2;
		chocolate[2] = c3;
		//Sort.BubbleSort(chocolate);
		Sort.quicksort(chocolate, 0, chocolate.length-1);
	
		for(Chocolate i: chocolate) {
			System.out.println(i);
		}
		
		System.out.println("\n");
		
		
		Employee e1 = new Employee("Era", 984000.5, new Date(119, 7, 30), "KZ_01" );
		Employee e2 = new Employee("Duka", 783000.5, new Date(121, 5, 17), "KZ_02" );
		Employee e3 = new Employee("Aset", 899400.5, new Date(120, 1, 3), "KZ_03" );
		
		Employee[] employees = new Employee[3];
		employees[0] = e1;
		employees[1] = e2;
		employees[2] = e3;
		Sort.quicksort(employees, 0, employees.length-1);
		//Sort.BubbleSort(employees);
		for(Employee i: employees) {
			System.out.println(i);
		}
	}
}
