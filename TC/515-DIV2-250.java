import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class FortunateNumbers {
	public int getFortunate(int[] a, int[] b, int[] c) {
		int i;
		int j;
		int k;
		
		Set<Integer> set = new TreeSet<Integer>();
		
		for (i = 0; i < a.length; i++) {
			for (j = 0; j < b.length; j++) {
				for (k = 0; k < c.length; k++) {
					int s = a[i] + b[j] + c[k];
					
					if (func(s)) set.add(s);
				}	
			}
		}
		
		return set.size();
	}
	
	public boolean func(int x) {
		if (x == 0) return false;
		
		for ( ; x > 0; ) {
			int d = (x % 10);
			
			if (d != 5 && d != 8) return false;
			
			x /= 10;
		}
		
		return true;
	}
}
//Powered by [KawigiEdit] 2.0!
