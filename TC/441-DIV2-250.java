import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class DifferentStrings {
	public int minimize(String A, String B) {
		int ans = Integer.MAX_VALUE;
		
		for (int i = 0; i <= B.length() - A.length(); i++) {
			int now = 0;
			
			for (int j = 0; j < A.length(); j++) {
				if (A.charAt(j) != B.charAt(i + j)) {
					now += 1;
				}
			}
			ans = Math.min(ans, now);
		}
		return ans;
	}	
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
