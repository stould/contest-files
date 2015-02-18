import java.util.*;
import java.math.*;

public class TwiceString {
	public String getShortest(String s) {	
		for(int i = 1; i < s.length(); i++) {
			if(s.startsWith(s.substring(i))) {
				return s + s.substring(s.length() - i);
			}
		}		
		return s + s;
	}	
}


// Powered by FileEdit
