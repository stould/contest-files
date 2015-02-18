import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TheBlackJackDivTwo {
	public int score(String[] cards) {
		int ans = 0;
		
		for (String s: cards) {
			ans += value(s);
		}
		
		return ans;
	}
	
	public int value(String s) {
		if (s.charAt(0) >= '0' && s.charAt(0) <= '9') {
			return s.charAt(0) - '0';
		} else if (s.charAt(0) == 'A') {
			return 11;
		} else {
			return 10;
		}
	}
}

//Powered by [KawigiEdit] 2.0!
