import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class MinimumSquareEasy {
	public long minArea(int[] x, int[] y) {
		long ans = Long.MAX_VALUE;
		int N = x.length;
		
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int h_x = Integer.MIN_VALUE;
				int l_x = Integer.MAX_VALUE;

				int h_y = Integer.MIN_VALUE;
				int l_y = Integer.MAX_VALUE;
				
				for (int k = 0; k < N; k++) {
					if (k != i && k != j) {
						h_x = Math.max(h_x, x[k]);
						l_x = Math.min(l_x, x[k]);
						
						h_y = Math.max(h_y, y[k]);
						l_y = Math.min(l_y, y[k]);
					}
				}
				
				long s_x = (h_x - l_x + 2);
				long s_y = (h_y - l_y + 2);
				
				ans = Math.min(ans, Math.max(s_x, s_y) * Math.max(s_x, s_y));
			}
		}
		
		return ans;
	}	
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
