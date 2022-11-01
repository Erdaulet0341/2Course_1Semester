package problem3;

public class Rock extends Piece{
	
	public Position a;
	public Position b;
	
	public Rock() {
		
	}
	
	public void setPosition(Position a, Position b) {
		this.a = a;
		this.b = b;
	}

	public boolean isLegalMove(Position a, Position b) {
		if(a.equals(b)) return false;
		if(a.y == b.y && a.x !=b.x) return true;
		if(a.x == b.x && a.y != b.y) return true;
		return false;
	}
	
	public String toString() {
		if(isLegalMove( a, b)) return "Rock CAN move new position";
		return "Rock CAN NOT move new position";
	}

	
}
