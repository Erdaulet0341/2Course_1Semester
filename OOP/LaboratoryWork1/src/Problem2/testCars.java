package Problem2;


public class testCars {

	public static void main(String[] args) {
		Cars mercedes = new Cars("MERCEDES-BENZ", 2020, "Red", Transmissions.MANUAL);
		Cars bmw = new Cars("BMW-M5", 2018, "Blue", Transmissions.MANUAL);
		Cars toyota = new Cars("TOYOTA-CAMRY", 2019, "Black", Transmissions.AUTOMATIC);
		Cars lexus = new Cars("LEXUS-570", 2022, "White", Transmissions.AUTOMATIC);
		Cars matis = new Cars("MATIZ", 2010, "Green");
		
		for(Cars cur: Cars.cars) 
			System.out.println(cur);
		
		System.out.println("Current color " + mercedes.getColor());
		mercedes.Edit("Black");
		System.out.println("New color " + mercedes.getColor());
		
		System.out.println("Matiz id = " + matis.getId());
		
		Cars Subaru = new Cars();
		Subaru.setName("Subaru-SportCar-GCK0032");
		System.out.println(Subaru.getName());
	}

}