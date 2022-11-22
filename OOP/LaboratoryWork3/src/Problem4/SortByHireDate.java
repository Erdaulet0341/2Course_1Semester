package Problem4;

import java.util.Comparator;

public class SortByHireDate implements Comparator<Employee>{

	
	@SuppressWarnings("deprecation")
	public int compare(Employee o1, Employee o2) {
		if(o1.getHireDate().getYear() == o2.getHireDate().getYear()) return 0;
		else if(o1.getHireDate().getYear() > o2.getHireDate().getYear()) return 1;
		return -1;
	}
	
}
