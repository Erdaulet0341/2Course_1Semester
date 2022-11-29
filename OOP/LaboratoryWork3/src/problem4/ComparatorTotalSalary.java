package problem4;

import java.util.Comparator;

public class ComparatorTotalSalary implements Comparator<Manager>{

	@Override
	public int compare(Manager o1, Manager o2) {
		double totSum1 = o1.getBonus()+o1.getSalary();
		double totSum2 = o2.getBonus()+o2.getSalary();
		if(totSum1 == totSum1) {
			new SortByHireDate().compare(o1, o2);
		}
		return (int) (totSum1-totSum2);
	
	}
	
}
