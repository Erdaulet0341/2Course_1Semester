package working3;

//import java.util.*;
import java.io.*;
import java.util.regex.Pattern;

public class TestNotUInput {

	public static void main(String[] args) {
		

				DataBase db = new DataBase();
				Student s1 = new Student("21SFT21", "Arman", "arman@kbtu.kz", "Turgut Ozala 80", "dasfads", Faculties.FIT, 2,
						StudentDegree.BACHELOR);
				Student s2 = new Student("22SKMF1", "Abdos", "abdos@kbtu.kz", "Turgut Ozala 80", "aidos2003", Faculties.KMA, 1,
						StudentDegree.BACHELOR);
				Student s3 = new Student("20SIS14", "Nurbek", "nurbek@kbtu.kz", "Turgut Ozala 80", "Nur53(&", Faculties.ISE, 3,
						StudentDegree.BACHELOR);
				Student s4 = new Student("19SDS78", "Aiman", "aiman@kbtu.kz", "Turgut Ozala 80", "Aima5d", Faculties.BS, 4,
						StudentDegree.PHD);
				db.addUsers(s1);
				db.addUsers(s2);
				db.addUsers(s3);
				db.addUsers(s4);

				Admin admin = new Admin("21A4656", "Nazgul", "nazgul@kbtu.kz", "Turgut Ozala 80", "NAz456!", 1450000);
				db.addUsers(admin);

				Teacher t1 = new Teacher("21T4FITL656", "Asqar", "asqar@kbtu.kz", "Turgut Ozala 80", "a;sjfl65", 1700000,
						TeacherDegree.PROFESSOR);
				Teacher t2 = new Teacher("21T7KMAL791", "Aibek", "aibek@kbtu.kz", "Turgut Ozala 80", "s6d45aer", 1100000,
						TeacherDegree.SENIORLECTURER);
				Teacher t3 = new Teacher("21T9ISEL478", "Chardon", "chardonr@kbtu.kz", "Turgut Ozala 80", "45ad4ga", 1500000,
						TeacherDegree.BASICTEACHER);
				Teacher t4 = new Teacher("21T9ISEL478", "Nurmukhan", "dadanr@kbtu.kz", "Turgut Ozala 80", "42324ga", 15000000,
						TeacherDegree.BASICTEACHER);

				db.addUsers(t1);
				db.addUsers(t2);
				db.addUsers(t3);
				db.addUsers(t4);

				Manager manager = new Manager("21M4656", "Samat", "samat@kbtu.kz", "Turgut Ozala 80", "Nsera6d!", 789000,
						ManagerTypes.OR);
				Manager manager1 = new Manager("21M4656", "Sam", "sam@kbtu.kz", "Turgut Ozala 80", "Nsera236d!", 7890000,
						ManagerTypes.OR);

				db.addUsers(manager);
				db.addUsers(manager1);

				// db.getStudent();
				// db.viewStudentSortedByName();
//				db.viewEmployeeSortBySalaty();
//				System.out.println(db.employees);
//				t2.doResearch("OOP projects");

//				
				s1.registrateCourse("IKT", db);
				s1.registrateCourse("Database", db);
				s1.registrateCourse("DiscreteMath", db);

				s2.registrateCourse("IKT", db);
				s2.registrateCourse("Database", db);
				s2.registrateCourse("DiscreteMath", db);

//				s1.registrateCourse("DiscreteMath", db);
////				
				Marks m1 = new Marks(5, "21-12-2022", true);
				Marks m5 = new Marks(8, "23-12-2022", true);
				Marks m6 = new Marks(5, "21-12-2022", true);
				Marks m7 = new Marks(8, "23-12-2022", true);
				Marks m3 = new Marks(10, "21-12-2022", false);
				Marks m9 = new Marks(10, "21-12-2022", false);
				Marks a = new Marks(20, 20, 40);
				Marks a1 = new Marks(5, 5, 4);
				Marks a2 = new Marks(20, 20, 40);
				Marks a3 = new Marks(25, 25, 40);
				Marks a4 = new Marks(15, 25, 40);
				Marks a5 = new Marks(23, 20, 40);

//				
				t1.putMarks(db.c1, s1, m1);
				t1.putMarks(db.c1, s2, m6); // database

				t1.putMarks(db.c2, s1, m3); // discrete
				t1.putMarks(db.c2, s2, m9);

				t1.putMarks(db.c3, s1, m1);
				t1.putMarks(db.c3, s2, m7); // ikt

				t1.putAttectation(db.c1, s1, a1);
				t1.putAttectation(db.c1, s2, a2);

				t1.putAttectation(db.c2, s1, a1);
				t1.putAttectation(db.c2, s2, a3);

				t1.putAttectation(db.c3, s1, a4);
				t1.putAttectation(db.c3, s2, a5);

//				s1.viewAttestation();
//				s1.viewMarks();
//				System.out.println(s1.marks);

//				System.out.println(s1.getCourse());
//				s1.viewCourse();
				s1.viewTranscript();
//				s1.calculateGpaTotal();
				s2.viewTranscript();
				
				s1.viewStudentCourse(db);

//				manager.makeReport(db);

//				System.out.println(db.FailedStudents);
//				System.out.println(s1.calculateGpaTotal());
//				s1.viewFinancialCabinet(db);
//				db.FailedStudents.firstElement().calculateGpaTotal();
//				s1.viewStudentCourse();
//				s2.viewTranscript();
//				
//				News news = new News("All finals will be online", "15.12.2022");
//				manager.manageNews(db, news);
//				
////				s1.viewNews(db);
//				
//				s1.makeRequests(RequestsForStudent.MAKEONAY, db);
//				s1.makeRequests(RequestsForStudent									.MAKEID, db);
//				System.out.println(s1.getRequests());

//				System.out.println(s1.calculateGpaTotal());
//				
//				db.getRatingStudent();

//				db.fill(db);
				
//				manager.makeReport(db);
				db.ratingTeachers.replace((Teacher) t1, 9);
				db.ratingTeachers.replace((Teacher) t2, 15);
				db.ratingTeachers.replace((Teacher) t3, 4);
				db.ratingTeachers.replace((Teacher) t4, 17);
//				
//				db.getRatingTeacher();
//				
//				System.out.println(db.ratingTeachers);
//				
//				HallOfFame.getTop3Teachers(db);

//				String t = "dadasda";
//				
//				Message me = new Message(t,"21:00");
//				manager.sendMessage(manager1, me);
//				
//				manager1.viewMessages();
//				String t = "Arman";
//				String s = "Ar";
//				String z = "^(" + s + ").*$";
//				System.out.println(t.matches(z));
//				db.getRatingTeachers();

			}

		}

}

}
