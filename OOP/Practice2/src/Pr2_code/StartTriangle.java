package Pr2_code;

public class StartTriangle {
	public int width;
	
	public StartTriangle(int n) {
		width = n;
	}
	

	
	public StartTriangle() {	
	}
	
	public String toString() {
		for (int i=0; i<width ; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == (width -1)) {
					System.out.print("");
				}
				else
					System.out.print("[*]");
			}
			if (i == (width -1)){
				continue;
			}
			else
				System.out.println();
		}
		return "[*]";
		
	}
}
