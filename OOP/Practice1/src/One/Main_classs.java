package One;
import java.util.Scanner;

public class Main_classs {

	public static void main(String[] args) {
		Person era = new Person(120, "Era");
		//era.height = 120;
		System.out.println(era.name + "="+ era.height + "cm") ;
		Person duka = new Person();
		System.out.println(duka.height) ;
		era.say("Aset" + "\n" + "\n");
		
		//Scanner in = new Scanner(System.in);
		//String name_task1 = in.next();
		//Task2 t2 = new Task2();
		//t2.task_2();
		Student st = new Student(180, "Dauren", 3);
		System.out.println(st.course);
		System.out.println(st.name);
		st.tell();
	}

}
