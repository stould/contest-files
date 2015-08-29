import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class RestaurantManager {
	public int allocateTables(int[] tables, int[] groupSizes, int[] arrivals, int[] departures) {
		int ans = 0;
		int N = groupSizes.length;
		int M = tables.length;
		
		int[] free = new int[M];
		
		Arrays.fill(free, -1);
		
		for (int i = 0; i < N; i++) {
			int id = -1;
			int best = Integer.MAX_VALUE;
			
			for (int j = 0; j < M; j++) {
				if (tables[j] >= groupSizes[i]) {
					if (free[j] == -1 || free[j] <= arrivals[i]) {
						if (tables[j] < best) {
							best = tables[j];
							id = j;
						}
					}
				}
			}
//			System.out.println(i + " " + id);
			if (id == -1) {
				ans += groupSizes[i];
			} else {
				free[id] = departures[i];
			}
		}
		
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
