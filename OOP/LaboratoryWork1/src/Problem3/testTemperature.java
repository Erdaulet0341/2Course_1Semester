package Problem3;

import java.util.Scanner;

public class testTemperature {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter your value: ");
		double value = in.nextDouble();
		System.out.print("Enter your scale: ");
		char scale = in.next().charAt(0);
		Temperature temperature = new Temperature(value, scale);
		if(scale == 'C') {
			temperature.setCelsius();;
			System.out.println(value + "C = "+ temperature.getFahrenheit() + temperature.getScale());
		}
		else {
			temperature.setFahrenheit();
			System.out.println(value + "F = " + temperature.getCelsius() + temperature.getScale());
		}
	}

}
