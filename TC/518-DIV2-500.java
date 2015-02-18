import java.util.*;
import java.math.*;

public class LargestSubsequence {
	public String getLargest(String s) {
		String ans = "";
		int i = 0;
		while(true) {
			if(i >= s.length()) break;
			char max = 'a' - 1;
			int index = s.length();
			for( ; i < s.length(); i++) {
				if(s.charAt(i) > max) {
					max = s.charAt(i);
					index = i;
				}
			}
			ans += max;
			i = index + 1;
		}
		
		return ans;
	}	
}


// Powered by FileEdit
