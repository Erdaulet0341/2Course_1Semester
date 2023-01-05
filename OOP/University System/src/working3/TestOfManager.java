package working3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.util.Scanner;

public class TestOfManager {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Admin admin = new Admin("21A4656", "Nazgul", "nazgul@kbtu.kz", "Turgut Ozala 80", "NAz456", 1450000);
		Classroom classroom1 = new Classroom(342, ClassRoomType.CLASSFORLECTURE);
		Classroom classroom2 = new Classroom(406, ClassRoomType.CLASSFORPRACTISE);

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
				if (admin.checkLoginPassword(login, password, db) && typeUser == 'M') {
					Manager manager = (Manager) db.getUsetByLogin(login);
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
								case 6: // add course
									System.out.print("Assign title: ");
									String title = in.readLine();
									System.out.print("Assign credits: ");
									int credits = Integer.parseInt(in.readLine());
									System.out.print("Assign code: ");
									String code = in.readLine();
									System.out.print("Assign teacherId: ");
									String teacherId = in.readLine();
									System.out.print("Assign whatYearOfStudentCanGetThisCourse: ");
									int whatYear = Integer.parseInt(in.readLine());
									Course newCourse = new Course(title, credits, code, teacherId, whatYear);
									manager.addCourse(newCourse, db);
									System.err.println("Course added!");
									break;
								case 7: // integrate some news
									System.out.print("Enter text of news: ");
									String text = in.readLine();
									LocalDate date = LocalDate.now();
									News news = new News(text, date.toString());
									manager.manageNews(db, news);
									System.err.println("News added!");
									break;
								case 8: // view student
									System.out.print("Input id or name of Student: ");
									String idname = in.readLine();
									db.getUser(idname);
									break;
								case 9: // view requests
									System.out.println();
									db.getAllRequests();
									break;
								case 10: // assign schedule
									System.out.println("For who you wanna assign schedule: \n1. Teacher \n2. Student");
									int choose = Integer.parseInt(in.readLine());
									System.out.println("How many lessons do you wanna add? ");
									int cnt = Integer.parseInt(in.readLine());
									;
									for (int i = 0; i < cnt; ++i) {
										System.out.print("Select a day to lesson: ");
										String day = in.readLine();
										System.out.print("Select a lesson to assign: ");
										String lesson = in.readLine();
										System.out.print("Select a time to assign: ");
										String time = in.readLine();
										System.out.print("Select a lesson type (LECTURE,PRACTISE,LABARATORY): ");
										String type = in.readLine();
										System.out.print("Select a lesson format (ONLINE,OFFLINE): ");
										String format = in.readLine();
										Lesson lesson1 = null;
										Lesson lesson2 = null;
										Course course = null;
										course = db.findCourse(lesson);
										if (format.toString().equals("LECTURE")) {
											lesson1 = new Lesson(Day.valueOf(day), course, time, LessonType.valueOf(type),
													LessonFormat.valueOf(format), classroom1);
										} else {
											lesson2 = new Lesson(Day.valueOf(day), course, time, LessonType.valueOf(type),
													LessonFormat.valueOf(format), classroom2);
										}
										if (choose == 1) {
											System.out.print("Enter your teacher id: ");
											String s = in.readLine();
											Teacher teacher = (Teacher) db.getUsetByLogin(s);
											teacher.teacherSchedule.add(lesson1);
										}
										else
											System.out.print("Enter your student id: ");
											String s = in.readLine();
											Student student = (Student)db.getUsetByLogin(s);
											student.studentSchedule.add(lesson2);
									}
									System.out.println();
									System.err.println("DONE! ");
									break;
								case 11:
									manager.makeReport(db);
									break;
								case 12:
									System.out.println(manager);

								}

								System.out.println(
										"5. Exit \n6. Add course \n7. Add news \n8. View Student \n9. View requests \n10. Assign schedule \n11. Make report of Students \n12. Info about you");
								operationNumber = Integer.parseInt(in.readLine());
							} while (operationNumber != 5);

							break;
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
