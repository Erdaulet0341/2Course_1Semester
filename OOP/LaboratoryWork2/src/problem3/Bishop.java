package problem3;

public class Bishop extends Piece{
	public Position a;
	public Position b;
	
	public Bishop() {
		
	}
	
	public void setPosition(Position a, Position b) {
		this.a = a;
		this.b = b;
	}


	public boolean isLegalMove(Position a, Position b) { // e4, d5
		if(a.equals(b)) return false;
		if(Math.abs(b.x-a.x)==Math.abs(b.y-a.y)) return true; // 1==1
		return false;
	}
	
	public String toString() {
		if(isLegalMove( a, b)) return "Bishop CAN move new position";
		return "Bishop CAN NOT move new position";
	}
}
