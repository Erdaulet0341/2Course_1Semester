package Lab2_python;
import java.util.Scanner;
import java.util.HashMap;

public class Ten {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		HashMap<String, String> map = new HashMap<String, String>();
		
		for (int i=0; i<n; i++) {
			String s = in.next();
			for (int j = 0; j<s.length(); j++) {
				char c = s.charAt(j);
				if (c >= '0' && c<='9') {
					if (c >= 'a' && c<='z') {
						if (c >= 'A' && c<='Z') {
							map.put(s, "111");
						}
				}
			}
		}
		}
			
		for (String j : map.keySet()) {
			System.out.println(j + "+");;
		}
		
	}

}
