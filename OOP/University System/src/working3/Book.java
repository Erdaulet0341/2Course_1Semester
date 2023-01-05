package working3;

import java.io.Serializable;
import java.util.Objects;

public class Book implements Serializable{
    

	private static final long serialVersionUID = 1L;	

	private String name;
    
    private int code;
    
    private String author;
    
    Book(String name,int code,String author){
    	this.name = name;
    	this.code = code;
    	this.author = author;
    }

    
    public String getName() {
        return this.name;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public int getCode() {
        return this.code;
    }
    
    public void setCode(Integer code) {
        this.code = code;
    }
    
    public String getAuthor() {
        return this.author;
    }
    
    public void setAuthor(String author) {
        this.author = author;
    }
    
    
    
    @Override
	public int hashCode() {
		return Objects.hash(author, code, name);
	}


	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Book other = (Book) obj;
		return Objects.equals(author, other.author) && code == other.code && Objects.equals(name, other.name);
	}


	public String toString() {
    	return "[ Name: " + name + "Code: " + code + "Author: " + author + " ]";
    }
    
    
}
