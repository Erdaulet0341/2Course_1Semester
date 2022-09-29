package Problem1;

public class Data {
	private int number;
	private double average;
	private double maximum = 0;
	static int cnt=0;
	static double sum=0;
	
	public Data() {}
	
	public void setNumber(int number) {
		this.number = number;
		if(maximum<number) {
			maximum = number;
		}
		sum+=number;
		cnt++;
	}
	
	public  double getMaximum() {
		return maximum;
	}
	
	public double getAverage() {
		return sum/cnt;
	}
}
