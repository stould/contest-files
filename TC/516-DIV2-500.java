import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class NetworkXOneTimePad {
	public int crack(String[] plaintexts, String[] ciphertexts) {		
		Set<String> keys = new HashSet<String>();
		
		for (int i = 0; i < plaintexts.length; i++) {
			for (int j = 0; j < ciphertexts.length; j++) {
				keys.add(xor(plaintexts[i], ciphertexts[j]));
			}
		}
		
		int ans = 0;
		
		for (String str: keys) {	
			boolean ok = true;
			
			for (String cp: ciphertexts) {
				String rev_key = xor(str, cp);
				
				boolean found = false;
				
				for (String plain: plaintexts) {
					if (rev_key.equals(plain)) {
						found = true;
					}
				}
				
				if (!found) {
					ok = false;
				}
			}
			
			if (ok) ans += 1;
		}
		
		return ans;
	}
	public String xor(String a, String b) {
		String ans = "";
		
		for (int i = 0; i < a.length(); i++) {
			ans +=  ((int)(a.charAt(i) - '0') ^ (int)(b.charAt(i) - '0'));
		}
		
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
