package problem4;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Dates {
	Calendar calendar = Calendar.getInstance();
	SimpleDateFormat sdf = new SimpleDateFormat("dd-M-yyyy");
	
	public Date getTime(String s) throws ParseException {
		Date date = sdf.parse(s);
		return date;
	}
}