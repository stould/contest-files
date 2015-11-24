import java.util.*;
import java.math.*;

public class LetterStrings {
	public int sum(String[] s) {
		int ans = 0;
		for(int i = 0; i < s.length; i++) {
			s[i] = s[i].replaceAll("-", "");
			ans += s[i].length();
		}
		return ans;		
	}	
}


// Powered by FileEdit
