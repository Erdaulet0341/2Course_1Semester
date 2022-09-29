package Pr1_code;
import java.util.HashMap;
//import java.util.Scanner;

public class hashmap {
	void Task_3() {
		//Scanner in = new Scanner(System.in);
		//int n = in.nextInt();
		
		String arr[][] = {{"Era" ,"14"}, {"Duka", "16"}, {"Aset", "20"}, {"Vlad", "14"}};
		
		HashMap<String, String> people = new HashMap<String , String>();
		//int n = 1;
		//int k =0;
		
		for(int i = 0 ; i < arr.length ; i++){
			people.put(arr[i][0], arr[i][1]);
		}
		
		for (String i : people.keySet()) {
		      System.out.println("Name: " + i + " Age: " + people.get(i));
		    }
		}
		
}

