package working3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.util.Scanner;

public class TestOfStudent {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Admin admin = new Admin("21A4656", "Nazgul", "nazgul@kbtu.kz", "Turgut Ozala 80", "NAz456", 1450000);

		try {
			DataBase db = DataBase.getDatabase();
			
			do {
				System.out.print("Enter your login(-1 to close System): ");
				String login = in.readLine();
				if (login.equals("-1")) {
					System.err.println("Goodbye!!!");
					DataBase.write();
					System.exit(0);
				}
				System.out.print("Enter your password: ");
				String password = in.readLine();
				boolean check = true;
				char typeUser = login.charAt(2);
				int operationNumber = 0;
				if (admin.checkLoginPassword(login, password, db) && typeUser == 'S') {
					Student student = (Student)db.getUsetByLogin(login);
					do {
						System.out.println("\n0. View HallOfFame \n1. Exit \n2. Change password \n3. View news \n4. Next page");
						operationNumber = Integer.parseInt(in.readLine());
						switch (operationNumber) {
						case 0:
							System.out.println("Students: ");
							HallOfFame.getTop3Students(db);
							System.out.println();
							System.out.println();
							System.out.println("Teachers: ");
							HallOfFame.getTop3Teachers(db);
						case 1:
							break;
						case 2:
							System.out.print("Enter new password: ");
							String passWord1 = in.readLine();
							db.changePassword(login, passWord1);
							break;
						case 3:
							admin.viewNews(db);
							break;
						case 4:
							do {
								switch (operationNumber) {
								case 6: // view all marks
									student.viewMarks();
									System.out.println();
									break;
								case 7: // view transcript
									student.viewTranscript();
									System.out.println();
									break;
								case 8: // registrate for course
									System.out.println("All courses in DataBase: ");
									for (Course i : db.courses) {
										System.err.println(i);
									}
									System.out.print("Enter your course name: ");
									String courseName = in.readLine();
									if (student.registrateCourse(courseName, db) == true) {
										System.out.println();
										System.err.println("DONE!");
										System.err.println("REGISTRED COURSE:");
									} else {
										System.out.println();
										System.out.println("You can't registrate for this course! ");
									}
									break;
								case 9: // view courses
									student.viewStudentCourse(db);
									System.out.println();
									break;
								case 10: // make request
									System.out.println(java.util.Arrays.asList(RequestsForStudent.values()));
									String requestName = in.readLine();
									RequestsForStudent request = RequestsForStudent.valueOf(requestName);
									student.makeRequests(request, db);
									System.err.println();
									System.err.println("REQUEST SENT!");
									System.err.println();
									break;
								case 11: // view requests
									student.viewRequests();
									break;
								case 12: // viewTeacherOfSpecificCourse
									System.out.print("Input Course title: ");
									String courseTitle = in.readLine();
									db.viewTeacherOfSpecificCourse(courseTitle);
									break;
								case 13: // enter organization
									System.out.println(java.util.Arrays.asList(Organizations.values()));
									String organization = in.readLine();
									student.enterOrganization(organization);
									System.err.println();
									System.err.println("DONE!");
									System.err.println();
									break;
								case 14: // view organization
									System.out.println();
									System.err.println(student.getOrganization());
									break;
								case 15:
									search: {
										for (User u : db.users) {
											if (u.getClass() == Teacher.class) {
												System.out.print(u.getUserName() + " (from 1 to 10): ");
												int rating = Integer.parseInt(in.readLine());
												if (rating < 1) {
													System.err.println(
															"Yeah, i know how much you hate this teacher,but you can't do that!");
													break search;
												}
												if (rating > 10) {
													System.err.println(
															"It seems you are rating Pakita right now, okay, i'll let you to do that");
												}
												int temp = db.ratingTeachers.get(u);
												temp += rating;
												db.ratingTeachers.replace((Teacher) u, temp);
											}
										}
									}
									System.err.println();
									System.err.println("DONE!");
									System.err.println();
									break;
								
								case 16:
									student.viewFinancialCabinet(db);
									break;
								case 17:
									db.viewAllBooks();
									System.out.print("Input name of book you want to get: ");
									String nameOfBook = in.readLine();
									student.getBook(nameOfBook, db);
									System.err.println();
									System.err.println("DONE!");
									System.err.println();
									break;
								}
								System.out.println(
										"5. Exit \n6. View AllMarks \n7. View Transcript \n8. Registration course \n9. View Courses \n10. Make a request"
												+ " \n11. View Requests \n12. View Teacher of Course \n13. Enter Organisation \n14. View Organization \n15. Rate Teacher \n16. View Financial cabinet"
												+ " \n17. Get Book ");
								operationNumber = Integer.parseInt(in.readLine());

							} while (operationNumber != 5);

						}
					} while (operationNumber != 1);
				} else {
					System.out.println("Incorrect data!");
				}
			} while (true);
		}
		catch(Exception e) {
			System.out.println("Smth went wrong,saving data! ");
			DataBase.write();
		}
		

	}

}
