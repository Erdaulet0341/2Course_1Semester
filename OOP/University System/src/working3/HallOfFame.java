package working3;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map.Entry;

public class HallOfFame implements Serializable{
	
	private static final long serialVersionUID = 1L;

	public static void getTop3Students(DataBase db) {
		int cnt = 1;
		Entry<Student,Double> entry1 = null;
		HashMap<Student,Double> temp = db.getRatingStudent();
		for(Entry<Student,Double> entry : db.ratingStudents.entrySet()) {
			System.out.println("Top " + cnt + ": " +  entry.getKey().getUserName());
			if(cnt==1)entry1 = entry;
			else if(cnt==3) {
				break;
			}
			cnt++;
		}
		System.out.println();
		System.err.println("And KING of " + entry1.getKey().getFaculty() + " is.... ♛ " + entry1.getKey().getUserName() + " ♛, With " 
				+ entry1.getKey().calculateGpaTotal() + " GPA!");
	}
	
	
	public static void getTop3Teachers(DataBase db) {
		int cnt = 1;
		Entry<Teacher,Integer> entry1 = null;
    	HashMap<Teacher,Integer> temp = db.getRatingTeacher();
		for(Entry<Teacher,Integer> entry : temp.entrySet()) {
			System.out.println("Top " + cnt + ": " +  entry.getKey().getUserName());
			if(cnt==1)entry1 = entry;
			else if(cnt==3) {
				break;
			}
			cnt++;
		}
		System.out.println();
		System.err.println("And KING among teachers" + " is.... ♛ " + entry1.getKey().getUserName() + " ♛, With " 
				+ entry1.getValue() + " points in total!");
		
	}
	
}