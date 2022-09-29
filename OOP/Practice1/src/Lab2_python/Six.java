package Lab2_python;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Arrays;

public class Six {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		HashMap<String, Integer> comp = new HashMap<String, Integer>();
		
		for (int i = 0; i<n; i++) {
				String s = in.next();
				int k = in.nextInt();
				//comp.put(s, k);
				if(comp.isEmpty() == true) {
					comp.put(s, k);
				}
				else if (comp.containsKey(s) != true) {
					comp.put(s, k);
				}
				else {
					int l = comp.getOrDefault(s, 500);
					int sum = l+k;
					comp.put(s, sum);
					sum = 0;
				}
			
		}
		
		int max = -1;
		
		for (String i :comp.keySet()) {
			//System.out.println(i + " " +comp.get(i));
			if (comp.get(i) > max) {
				max = comp.get(i);
			}
		}
		
		int size = comp.size();
		String arr[];
		arr = new String[size];
		int e = 0;
		System.out.println("size = " + size);
		for (String i : comp.keySet()) {
			arr[e] = i;
			e++;
		}
		Arrays.sort(arr);
		
		for (String i : comp.keySet()) {
			if (comp.get(i) == max ) {
				System.out.println(i + " is lucky!");
			}
			else {
				System.out.println(i + " is don't receive " + (max - comp.get(i)));
			}
		}
	}

}