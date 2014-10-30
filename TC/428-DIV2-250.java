import java.util.*;
import java.math.*;

public class ThePalindrome {
	public int find(String s) {
		if(is(s)) return s.length();
		for(int i = 0; i < s.length(); i++) {
			for(int j = i + 1; j <= s.length(); j++) {
				String tmp = s + s.substring(i, j);
				String tmp2 = s + new StringBuilder(s.substring(i, j)).reverse().toString();
				if(is(tmp) || is(tmp2)) {
					return s.length() + j - i;
				}
			}
		}	
		return s.length();	
	}	
	public boolean is(String s) {
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) != s.charAt(s.length() - 1 - i)) return false;
		}
		return true;
	}
}


// Powered by FileEdit
