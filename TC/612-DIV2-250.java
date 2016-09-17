import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class LeftAndRightHandedDiv2 {
	public int count(String S) {
		int ans = 0;
		
		for (int i = 0; i + 1 < S.length(); i++) {
			if (S.charAt(i) == 'R' && S.charAt(i + 1) == 'L') {
				ans += 1;
			}
		}
		
		return ans;	
	}
}

//Powered by KawigiEdit-pf 2.3.0!
