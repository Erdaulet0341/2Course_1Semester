package Pr2_code;

public class Main {
	public static void main(String[] args) {
//		Student s = new Student("era");
//		Student s1 = new Student("duka");
//		Student s2 = new Student("aset");
//		for (Student cur : Student.students) {
//			System.out.println(cur.getName());
//		}
		
//		StartTriangle small = new StartTriangle(3);
//		System.out.println(small.toString() + "\n");
//		
		Time t = new Time(13, 22 , 16);
		System.out.println(t.toUniversal());
		System.out.println(t.toStandetrd());
		Time t2 = new Time(4, 24, 23);
		System.out.println(t2.toUniversal());
		System.out.println(t2.toStandetrd());
	}
}
