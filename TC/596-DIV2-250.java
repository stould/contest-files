import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

								public class FoxAndSightseeing {
	public int getMin(int[] position) {
		int i;
		int N = position.length;
		int dist = 0;
		
		for (i = 1; i < N; i++) {
			dist += Math.abs(position[i] - position[i - 1]);
		}
		
		int ans = Integer.MAX_VALUE;	
				
		for (i = 1; i < N - 1; i++) {
			int n_dist = dist;
			
			n_dist += Math.abs(position[i - 1] - position[i + 1]);
			n_dist -= Math.abs(position[i] - position[i - 1]);
			n_dist -= Math.abs(position[i] - position[i + 1]);
			
			ans = Math.min(ans, n_dist);
		}
		
		return ans;
	}
								}

								//Powered by [KawigiEdit] 2.0!
