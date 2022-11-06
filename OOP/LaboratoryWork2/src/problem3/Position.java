package problem3;


public class Position {
	protected int y;
	protected char x;
	
	public Position() {
		
	};
	
	public  Position(String s)
	{
		char c = s.charAt(0); 
		int n = (int)s.charAt(1) - '0';
		this.x = c;
		this.y = n;
	}
	
	public int getY() {
		return y;
	}
	public char getX() {
		return x;
	}
	
	public boolean equals(Object o) {
		Position p = (Position)o; 
		if(x == p.x && y == p.y) return true;
		return false;
	}
	
}
