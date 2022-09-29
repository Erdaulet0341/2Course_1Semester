package Lab2_python;
import java.util.Scanner;
import java.util.Arrays;

public class two {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int arr[];
		arr = new int[n];
		for (int i=0; i<n; i++) {
			arr[i] = in.nextInt();
		}
		Arrays.sort(arr);
		
		int max1 = arr[n-1];
		int max2 = arr[n-2];
		System.out.print(max1 * max2);
	}

}
