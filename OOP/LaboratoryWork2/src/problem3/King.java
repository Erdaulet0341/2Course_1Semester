package problem3;

public class King extends Piece {
	public Position a;
	public Position b;
	
	public King() {
		
	}
	
	public void setPosition(Position a, Position b) {
		this.a = a;
		this.b = b;
	}


	public boolean isLegalMove(Position a, Position b) {
		if(a.equals(b)) return false; 
		if((a.x-1)==b.x || (a.x+1)==b.x) return true; // e4, e5
		if((a.y+1)==b.y || (a.y-1)==b.y) return true; //e4, f4
		return false;
	}
	
	public String toString() {
		if(isLegalMove( a, b)) return "King CAN move new position";
		return "King CAN NOT move new position";
	}
}
