package problem1;
import java.util.Vector;

public class TestShapes {

	public static void main(String[] args) {
		Cube cube1 = new Cube(3);
		Cylinder cylinder1 = new Cylinder(3, 4); 
		Sphere sphere1 = new Sphere(5);
		
		Vector<Shape> shapes = new Vector<Shape>();
		
		shapes.add(cube1);
		shapes.add(cylinder1);
		shapes.add(sphere1);
		
		for(Shape i: shapes) {
			System.out.println(i);
		}
	}
}

