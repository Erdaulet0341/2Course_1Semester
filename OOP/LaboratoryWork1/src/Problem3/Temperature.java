package Problem3;

public class Temperature {
	private double value;
	char degrees;
	
	static double degreesF;
	static double degreesC;
	
	
	public Temperature() {}
	
	public Temperature(char degrees) {
		this.degrees = degrees;
		this.value = 0;
	}
	public Temperature(double degreeF, double degreeC){
		{
	}
		
	}
	public Temperature(double value, char degrees) {
		this.value = value;
		this.degrees = degrees;
	}
	
	public void setCelsius() {
		if (degrees == 'C')
			degreesC = value;
	}
	public void setFahrenheit() {
		if (degrees == 'F')
			degreesF = value;
	}
	
	public void setBoth() {
		if (degrees == 'F')
			degreesF = value;
		else
			degreesC = value;
	}
	
	
	public double getCelsius() {
		degreesC = 5*(degreesF - 32)/9;
		return degreesC;
	}
	public double getFahrenheit() {
		degreesF = (9*(degreesC/5))+32;
		return degreesF;
	}
	
	public char getScale(){
		if (degrees == 'C')
			return 'F';
		else
			return 'C';
	}
}