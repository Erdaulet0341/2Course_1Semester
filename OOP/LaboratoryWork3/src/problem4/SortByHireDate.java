package problem4;

import java.util.Comparator;

import Pr2_code.Time;

public class SortByHireDate implements Comparator<Employee>{
	
	 public int compare(Employee o, Employee o2) {
	       return o.getHireDate().compareTo(o2.getHireDate());
	    }
	
}
