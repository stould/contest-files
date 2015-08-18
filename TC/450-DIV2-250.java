/*
aajjbb
*/
import java.util.*;
import java.math.*;

public class StrangeComputer {
	public int setMemory(String mem) {
		int ans = 0;
		
		for(int i = 0; i < mem.length(); i++) {
			if(mem.charAt(i) == '1') {
				char now = '1';
				ans += 1;
				for(int j = i + 1; j < mem.length(); j++) {
					if(mem.charAt(j) != now) {
						ans += 1;
						now = mem.charAt(j);
					}
				}
				break;
			}
		}
		
		return ans;	
	}	
}


// Powered by FileEdit
