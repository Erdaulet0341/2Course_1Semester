package working3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.util.Scanner;

public class TestOfTeacher {

	public static void main(String[] args) throws IOException {
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
				if (admin.checkLoginPassword(login, password, db) && typeUser == 'T') {
					Teacher teacher =(Teacher)db.getUsetByLogin(login);
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
								case 6: // put mark -> t2.putMarks(course.c2, s1, m1);
									System.out.print("Enter student id: ");
									String id = in.readLine();
									Student student = (Student)db.getUsetByLogin(id);
									System.out.print("Enter course code: ");
									String code = in.readLine();
									System.out.print("Enter point: ");
									int point = Integer.parseInt(in.readLine());
									System.out.print("Enter date: ");
									String date = in.readLine();
									System.out.print("Enter attendance: ");
									boolean attendance = Boolean.parseBoolean(in.readLine());

									Marks m1 = new Marks(point, date, attendance);
									
									Course tempCourse = new Course();
									for (Course i : student.studentCourses) {
										if (i.getCode().equals(code)) {
											tempCourse = i;
										}
									}
									if (tempCourse.getTitle() == null) {
										System.err.println("It is not registred to this course yet");
									} else {
										teacher.putMarks(tempCourse, student, m1);
										System.err.println("DONE!");
									}
									break;
								case 7: // view course
									teacher.viewTeacherCourse();
									System.out.println();
									break;
								case 8: // view students
									db.getStudent();
									break;
								case 9:
									System.out.println(java.util.Arrays.asList(RequestsForTeacher.values()));
									String requestName = in.readLine();
									RequestsForTeacher request = RequestsForTeacher.valueOf(requestName);
									teacher.makeRequests(request, db);
									System.err.println("REQUEST SENT!");
									break;
								case 10:
									teacher.viewRequests();
									break;
								case 11:
									System.out.print("Enter student id: ");
									String Studentid = in.readLine();
									Student student2 = (Student)db.getUsetByLogin(Studentid);
									System.out.print("Enter course code: ");
									String CourseCode = in.readLine();
									System.out.print("Enter first attestation: ");
									int firstAtt = Integer.parseInt(in.readLine());
									System.out.print("Enter second attestation: ");
									int secondAtt = Integer.parseInt(in.readLine());
									System.out.print("Enter final point: ");
									int finall = Integer.parseInt(in.readLine());
									Marks m2 = new Marks(firstAtt, secondAtt, finall);
									Course tempCourse2 = new Course();
									System.out.println(student2.studentCourses);
									for (Course i : student2.studentCourses) {
										if (i.getCode().equals(CourseCode)) {
											tempCourse2= i;
										}
									}
									if (tempCourse2.getTitle() == null) {
										System.err.println("It is not registred to this course yet");
									} else {
										teacher.putAttectation(tempCourse2, student2, m2);
										System.err.println("DONE!");
									}
									break;
								case 12:
									System.out.println();
									teacher.viewTeacherSchedule();
									System.out.println();
									break;
								case 13:
									System.out.println("For what lesson you want to open attendance? ");
									String lessonName = in.readLine();
									System.out.println("How long it will be opened(minute)?: ");
									int time = Integer.parseInt(in.readLine());
									System.err.println();
									System.err.println("DONE!");
									System.err.println();
									break;
								case 14:
									System.out.print("Type first letters of name: ");
									String name = in.readLine();;
									System.out.println();
									db.findStudent(name);
									System.out.println();
									break;

								case 15:
									System.out.println(teacher);
									break;
								}
								System.out.println(
										"5. Exit \n6. Put Mark \n7. View course \n8. View Students \n9. Make a request "
												+ "\n10. View requests \n11. Put Attestation \n12. View Teacher Schedule \n13. Open attendance \n14. Find a student by name \n15. Info about you");
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
