import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class GroupedWordChecker {
	public int howMany(String[] words) {
		int ans = 0;
		
		for (String s: words) {
			int N = s.length();
			
			boolean[] used = new boolean[30];
			
			boolean ok = true;
			
			for (int i = 0; i < N; i++) {
				int j = i + 1;
				
				if (used[s.charAt(i) - 'a']) {
					ok = false;
				}
				
				used[s.charAt(i) - 'a'] = true;
				
				while (j < N && s.charAt(j) == s.charAt(i)) {
					j += 1;
				}
				
				i = j - 1;
			}
			
			if (ok) ans += 1;
		}
		
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
