package problem5;

public class Test {
	public static void main(String[] args) {
		Circuit a = new Resistor(3);
		Circuit b = new Resistor(3);
		Circuit c = new Resistor(6);
		Circuit d = new Resistor(3);
		Circuit e = new Resistor(2);
		Circuit f = new Series(a, b);
		Circuit g = new Parallel(c, d);
		Circuit h = new Series(g, e);
		Circuit circuit = new Parallel(h, f);
		double R = circuit.getResistance();
		circuit.applyPotentialDiff(5);
		System.out.println(R);
		System.out.println(circuit.getPotentialDiff());
		System.out.println(circuit.toString());
	}
}
