package problem2;
import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("If you want to show info about all persons enter (info) or want to add a new person enter (add): ");
		String operation, person_type, name, address, program,school;
		int year;
		double fee, pay;
		operation = in.next();
		while(operation.equals("add")) {
			System.out.print("What do you want to add (person, student, staff), show results enter (info): ");
			person_type = in.next();
			
			if(person_type.equals("person")) {
				System.out.print("name: ");
				name = in.next();
				System.out.print("address: ");
				address = in.next();
				Person p = new Person(name, address);
			}
			else if (person_type.equals("student")) {
				System.out.print("name: ");
				name = in.next();
				System.out.print("address: ");
				address = in.next();
				System.out.print("program: ");
				program = in.next();
				System.out.print("year: ");
				year = in.nextInt();
				System.out.print("fee: ");
				fee = in.nextDouble();
				Student s = new Student(name, address, program, year, fee);
			}
			else if (person_type.equals("staff")) {
				System.out.print("name: ");
				name = in.next();
				System.out.print("address: ");
				address = in.next();
				System.out.print("school: ");
				school = in.next();
				System.out.print("pay: ");
				pay = in.nextDouble();
				Staff st = new Staff(name, address, school, pay);
			}
			else {
				break;
			}
		}
		if(operation.equals("info")) {
			System.out.print("First enter persons!!!");
		}
		else {
			for(Person i : Person.persons) {
				System.out.println(i);
			}
		}
	}
	
	/*
	 add
	 person
	 Era
	 Tolebi
	 student
	 Asem
	 Sefullina
	 Informational system
	 2
	 1854000
	 staff
	 Nurbek 
	 Zhandosova
	 NISH
	 1500
	 */

}
