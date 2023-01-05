package working3;

import java.io.*;
import java.io.Serializable;
import java.util.*;

public abstract class User implements Serializable {
	
	private static final long serialVersionUID = 1L;
	private String userID;

	private String userName;

	private String email;

	private String address;

	private String password;

	User() {

	}

	User(String userId, String userName, String email, String address, String password) {
		this.userID = userId;
		this.userName = userName;
		this.email = email;
		this.address = address;
		this.password = password;
	}

	public String getPassword() {
		return this.password;
	}

	public String getUserID() {
		return this.userID;
	}

	public void setUserID(String userID) {
		this.userID = userID;
	}

	String getUserName() {
		return this.userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getEmail() {
		return this.email;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getAddress() {
		return this.address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public void viewNews(DataBase db) {
		for (News i : db.news) {
			System.out.println(i);
		}
	}

	@Override
	public int hashCode() {
		return Objects.hash(address, email, userID, userName);
	}

	
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		User other = (User) obj;
		return Objects.equals(address, other.address) && Objects.equals(email, other.email)
				&& Objects.equals(userID, other.userID) && Objects.equals(userName, other.userName);
	}

	public String toString() {
		return "User [userID=" + userID + ", userName=" + userName + ", email=" + email + ", address=" + address
				+ ", password=" + password + "]";
	}
	
	
}
