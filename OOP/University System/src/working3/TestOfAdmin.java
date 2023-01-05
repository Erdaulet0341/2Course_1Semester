package working3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.util.Scanner;

public class TestOfAdmin {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Admin admin1 = new Admin("21A4656", "Nazgul", "nazgul@kbtu.kz", "Turgut Ozala 80", "NAz456", 1450000);
		try {
			DataBase db = DataBase.getDatabase();
			if(db.users.size() == 0) {
				admin1.addUsers(admin1, db);
			}
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
				if (admin1.checkLoginPassword(login, password, db) && typeUser == 'A') {
					Admin admin = (Admin)db.getUsetByLogin(login);
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
								case 5: // previous
									break;
								case 6: // add user
									System.out.print("What type of user you want to add: ");
									String userType = in.readLine();

									User u = UserFactory.getUser(userType);

									System.out.print("Add userId: ");
									String userId = in.readLine();
									u.setUserID(userId);
									System.out.print("Add userName: ");
									String userName = in.readLine();
									u.setUserName(userName);
									System.out.print("Add email: ");
									String userEmail = in.readLine();
									u.setEmail(userEmail);
									System.out.print("Add address: ");
									String userAdress = in.readLine();
									u.setAddress(userAdress);
									System.out.print("Add password: ");
									String userPassword = in.readLine();
									u.setPassword(userPassword);

									if (u.getClass() == Student.class) {
										System.out.print("Add faculty (UPPER LETTERS): ");
										String facultyName = in.readLine();
										Faculties faculty = Faculties.valueOf(facultyName);
										((Student) u).setFaculty(faculty);
										((Student) u).setYearOfStudy(1);
										((Student) u).setDegree(StudentDegree.BACHELOR);
										db.addUsers(u);
										db.checkForRatingStudent(u);
										System.err.println();
										System.err.println("Added");
										System.err.println();
										
									} else if (u.getClass() == Teacher.class) {
										System.out.print("Add degree: ");
										String degreeName = in.readLine();
										TeacherDegree teacherDegree = TeacherDegree.valueOf(degreeName);
										((Teacher) u).setDegree(teacherDegree);
										System.out.print("Salary: ");
										int salary = Integer.parseInt(in.readLine());
										((Teacher) u).setSalary(salary);
										db.addUsers(u);
										db.checkForRatingTeacher(u);
										System.err.println();
										System.err.println("Added");
										System.err.println();

									}else if (u.getClass() == Manager.class) {
										System.out.print("Salary: ");
										int salary = Integer.parseInt(in.readLine());
										((Manager) u).setSalary(salary);
										db.addUsers(u);
										System.err.println();
										System.err.println("Added");
										System.err.println();

									}else if (u.getClass() == Librarian.class) {
										System.out.print("Salary: ");
										int salary = Integer.parseInt(in.readLine());
										((Teacher) u).setSalary(salary);
										db.addUsers(u);
										System.err.println();
										System.err.println("Added");
										System.err.println();
									}
									break;
								case 7: // delete user
									System.err.print("Enter id of user");
									String id = in.readLine();
									db.deleteUser(id);
									System.err.println("Deleted");
									break;
								case 8: // update user
									System.out.print("What do you want to update?: \n");
									System.out.print("1. Update password: \n");
									System.out.print("2. Update email: ");
									int choice = Integer.parseInt(in.readLine());
									if (choice == 1) { // password update
										System.out.print("Enter id of user to update: ");
										String idOfUser = in.readLine();
										System.out.print("Enter new password: ");
										String passWord = in.readLine();
										db.changePassword(idOfUser, passWord);
									} else if (choice == 2) { // email update
										System.out.print("Enter id of user to update: ");
										String idOfUser = in.readLine();
										System.out.print("Enter new email");
										String email = in.readLine();
										db.changeEmail(idOfUser, email);
									}
									System.err.println("Updated");
									break;
								case 9:
									System.out.print("What type of sorted students do you want see: \n");
									System.out.print("1. Time registrate: \n");
									System.out.print("2. Sort by name: ");
									int choice2 = Integer.parseInt(in.readLine());
									if (choice2 == 1) {
										db.getStudent();
									} else if (choice2 == 2) {
										db.viewStudentSortedByName();
									}
									break;
								case 10:
									System.out.print("What type of sorted Employees do you want see: \n");
									System.out.print("1. Time registrate: \n");
									System.out.print("2. Sort by salary: ");
									int choice3 = Integer.parseInt(in.readLine());
									if (choice3 == 1) {
										db.viewEmployees();
									} else if (choice3 == 2) {
										db.viewEmployeeSortBySalaty();
									}
									break;
								case 11:
									System.out.println(admin);
								}
								System.out.println(
										"5. Exit \n6. Add user \n7. Delete user \n8. Update user \n9. View all Students \n10. View all Employees \n11. Info about you");
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
