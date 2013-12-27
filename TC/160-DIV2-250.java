import java.util.*;
import java.math.*;

public class Substitute {
	public int getValue(String key, String code) {
		String ans = "";
		for(int i = 0; i < code.length(); i++) {
			if(key.contains(""+code.charAt(i))) {
				ans += ""+ ((key.indexOf(code.charAt(i)) + 1) % 10);
			}
		}
		return ans.equals("") ? 0 : Integer.parseInt(ans);
	}	
}


// Powered by FileEdit
