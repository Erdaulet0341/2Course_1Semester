package working3;

import java.io.Serializable;
import java.util.Objects;

public class News implements Serializable{
    
	private static final long serialVersionUID = 1L;
	

	public News() {};
	
    public News(String text, String dateTime) {
		this.text = text;
		this.dateTime = dateTime;
	}

	private String text;
    
    private String dateTime;
    
    public String getText() {
        return this.text;
    }
    
    public void setText(String text) {
        this.text = text;
    }
    
    public String getDateTime() {
        return this.dateTime;
    }
    
    public void setDateTime(String dateTime) {
        this.dateTime = dateTime;
    }

	@Override
	public String toString() {
		return  text + ", time=" + dateTime;
	}

	@Override
	public int hashCode() {
		return Objects.hash(dateTime, text);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		News other = (News) obj;
		return Objects.equals(dateTime, other.dateTime) && Objects.equals(text, other.text);
	}
	
	
    
    
}
