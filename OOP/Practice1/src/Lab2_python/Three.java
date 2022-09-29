package Lab2_python;
import java.util.Scanner;

public class Three {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int arr[][];
		arr = new int[n][n];
		for (int i=0; i<n; i++) {
			arr[i][0]=i;
			arr[0][i] = i;
		}
		for (int i=0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (i == j) {
					arr[i][j] = i*j;
				}
			}
		}
		for (int i=0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
}
