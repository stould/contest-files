import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class PointErasingTwo {
	public int getMaximum(int[] y) {
		int N = y.length;
		int best = Integer.MIN_VALUE;
		
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int inside = 0;
				
				int ly = Math.min(y[i], y[j]);
				int hy = Math.max(y[i], y[j]);
				
				for (int k = i + 1; k < j; k++) if (i != k && j != k) {
					if (y[k] > ly && y[k] < hy) {
						inside += 1;
					} 
				}
				
				best = max(best, inside);
			}
		}
		
		return best;
	}	
	
	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!


