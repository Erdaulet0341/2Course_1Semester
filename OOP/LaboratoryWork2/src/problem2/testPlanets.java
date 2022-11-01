package problem2;
import java.util.HashSet;

public class testPlanets {

	public static void main(String[] args) {
		Mars m = new Mars(6.39e23, 3.3895*10e6, Atmosphere.CarbonDioxide, 2);
		Saturn s = new Saturn(5.683e26, 58.232*10e6, Atmosphere.Hydrogen, 3);
		
		HashSet<Planet> planets = new HashSet<Planet>();
		
		Planet p = m; //clone of mars
		Saturn s2 = new Saturn(5.683e26, 58.232*10e6, Atmosphere.Hydrogen, 3); // duplicate of saturn
		Mars m2 = new Mars(6.39e23, 3.3895*10e6, Atmosphere.CarbonDioxide, 0); // new planet 
		
		planets.add(m);
		planets.add(s);
		
		System.out.println(planets.contains(p)); // true 
		planets.add(p); // don't add
		
		planets.add(s2); // don't add
		planets.add(m2);// add, because numberOfProbes is various

		for(Planet i: planets) {
			System.out.println(i); // by overridding methods hashCode equals don't add duplicates
		}
		
		
		for(Planet i: planets) {
			System.out.println(i.facts()); // polymorphism
			System.out.println(i.getGravity()); // polymorphism
		}
	}

}
