package problem4;

import java.util.Date;
import java.util.Objects;
import java.util.Vector;

public class Employee extends Person implements Comparable<Employee>, Cloneable{
	private double salary;
	private Date hireDate;
	private String insuranceNumber;
	static Vector<Employee> employees;
	static {
		employees = new Vector<Employee>();
	}
	{
		employees.add(this);
	}
	
	public Employee() {};
	public Employee(String name, double salary, Date d, String insuranceNumber) {
		super(name);
		this.salary = salary;
		this.hireDate = d;
		this.insuranceNumber = insuranceNumber;
	}
	public Employee(String name, double salary) {
		super(name);
		this.salary = salary;
	}
	
	
	public double getSalary() {
		return salary;
	}
	public void setSalary(double salary) {
		this.salary = salary;
	}
	public Date getHireDate() {
		return hireDate;
	}
	public void setHireDate(Date hireDate) {
		this.hireDate = hireDate;
	}
	public String getInsuranceNumber() {
		return insuranceNumber;
	}
	public void setInsuranceNumber(String insuranceNumber) {
		this.insuranceNumber = insuranceNumber;
	}
	
	
	public int hashCode() {
		return Objects.hash(getName(), hireDate, insuranceNumber, salary);
	}
	public boolean equals(Object obj) {
		if(!super.equals(obj)) return false;
		Employee e = (Employee) obj;
		return hireDate == e.hireDate && insuranceNumber == e.insuranceNumber
				&& salary == e.salary;
	}
	
	public int compareTo(Employee e) {
		return (int) (this.salary - e.getSalary());
	}
	
	
	public Object clone() throws CloneNotSupportedException{
		Employee e = (Employee) super.clone();
		//e.hireDate = (Date) hireDate.clone();
		return e;
	}
	
	public String toString() {
		return super.toString() + "Employee [salary=" + salary + ", hireDate=" + hireDate + ", insuranceNumber=" + insuranceNumber + "]";
	}
		
}
