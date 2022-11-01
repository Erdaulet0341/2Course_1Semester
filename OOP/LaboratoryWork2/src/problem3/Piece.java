package problem3;

public abstract class Piece {
	public Position a;
	public Position b;
	
	public Piece() {
		
	}
	
	public void setPosition(Position a, Position b) {
		this.a = a;
		this.b = b;
	}

	public abstract boolean isLegalMove(Position a, Position b);
	
	public String toString() {
		if(isLegalMove( a, b)) return "Piece CAN move new position";
		return "Piece CAN NOT move new position";
	}
	
}
