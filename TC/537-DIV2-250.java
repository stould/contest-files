import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class KingXNewBaby {
	public String isValid(String name) {
		Set<Character> set = new TreeSet<Character>();
		
		int c = 0;
		
		for (int i = 0; i < name.length(); i++) {
			if (func(name.charAt(i))) {
				set.add(name.charAt(i));
			} else {
				c += 1;
			}
		}
		
		if (set.size() == 1 && name.length() - c == 2 && name.length() == 8) {
			return "YES";
		} else {
			return "NO";
		}
	}	
	
	public boolean func(char c) {
		return c == 'a' ||  c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
	
	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!


