import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class WolfDelaymaster {
	public String check(String str) {
		int i;
		
		while (true) {
			boolean ok = false;
			for (i = 1; i <= str.length(); i++) {
				if (valid(str.substring(0, i))) {
					str = str.substring(i);
					ok = true;
					break;					
				}
			}	
			if (!ok) break;
		}
		
		return str.length() == 0 ? "VALID" : "INVALID";
	}
	public boolean valid(String str) {
		int i, s = 0;
		
		for (i = 0; i < str.length() && str.charAt(i) == 'w'; i++);
		
		s = i;
		
		if (4 * s > str.length() || s == 0) return false;
		
		String wp = str.substring(0, s);
		String op = str.substring(s, 2 * s);
		String lp = str.substring(2 * s, 3 * s);
		String fp = str.substring(3 * s, 4 * s);
		
		return cnt(wp, 'w') == s && cnt(op, 'o') == s && cnt(lp, 'l') == s && cnt(fp, 'f') == s;
	}
	
	public int cnt(String str, char c) {
		int i, ans = 0;
		
		for (i = 0; i < str.length(); i++) {
			if (str.charAt(i) == c) ans += 1;
		}
		
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
