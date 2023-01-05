package working3;

import java.io.Serializable;

public class Librarian extends Employee implements Serializable{
	
	private static final long serialVersionUID = 1L;

	public Librarian() {
		
	}
    
    public Librarian(String userId, String userName, String email, String address, String password, int salary) {
		super(userId, userName, email, address, password, salary);
	}
    
    public void addBook(Book book,DataBase db) {
    	db.eBooks.add(book);
    }
    
    public void removeBook(int codeOfBook,DataBase db) {
    	for(Book book : db.eBooks) {
    		if(book.getCode() == codeOfBook) {
    			db.eBooks.remove(book);
    		}
    	}
    }
    
    

	
    
    
}
