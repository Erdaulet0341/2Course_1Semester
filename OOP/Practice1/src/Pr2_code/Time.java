package Pr2_code;

public class Time {
	public int hour;
	public int minute;
	public int second;
	
	public Time(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	
	public String  toUniversal() {
		String h = String.valueOf(hour);
		if (h.length()==1) {
			h = "0"+h;
		}
		String m = String.valueOf(minute);
		if (m.length()==1) {
			m = "0"+m;
		}
		String s = String.valueOf(second);
		if (s.length()==1) {
			s = "0"+s;
		}
		String time = h + ":" + m + ":" + s;
		return time;
	}
	
	public String toStandetrd() {
		if ( hour < 24 && hour >= 12) {
			int h = hour -12;
			String hh = String.valueOf(h);
			if (hh.length()==1) {
				hh = "0"+hh;
			}
			String m = String.valueOf(minute);
			if (m.length()==1) {
				m = "0"+m;
			}
			String s = String.valueOf(second);
			if (s.length()==1) {
				s = "0"+s;
			}
			String time = h + ":" + m + ":" + s + " PM"; 
			return time;
		}
		else {
			String h = String.valueOf(hour);
			if (h.length()==1) {
				h = "0"+h;
			}
			String m = String.valueOf(minute);
			if (m.length()==1) {
				m = "0"+m;
			}
			String s = String.valueOf(second);
			if (s.length()==1) {
				s = "0"+s;
			}
			String time1 = h + ":" + m + ":" + s + " AM";
			return time1;
		}
	}
}
