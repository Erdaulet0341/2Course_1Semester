package Pr2_code;

import java.util.Comparator;

public class Time implements Comparable<Time>,Comparator<Time>{
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
    
    public int compareTo(Time o) {
        if(hour == o.hour) {
            if(minute == o.minute) {
                return second - o.second;
            }
            else return minute - o.minute;
        }
        else return hour - o.hour;
    }

    @Override
    public String toString() {
        return "Time [hour=" + hour + ", minute=" + minute + ", second=" + second + "]";
    }

    @Override
    public int compare(Time o, Time o2) {
        if(o2.hour == o.hour) {
            if(o2.minute == o.minute) {
                return o2.second - o.second;
            }
            else return o2.minute - o.minute;
        }
        else return o2.hour - o.hour;
    }
	
}
