import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class MysteriousRestaurant {
	public int maxDays(String[] prices, int budget) {
		int N = prices.length;
		
		int l = 0;
		int h = N;
		int best = Integer.MIN_VALUE;
		
		for ( ; l <= h; ) {
			int m = (l + h) / 2;
			
			if (func(prices, budget, m)) {
				l = m + 1;
				best = Math.max(best, m);
			} else {
				h = m - 1;
			}
		}	
		
		return best;
	}	
	
	public boolean func(String[] prices, int budget, int D) {
		int N = prices.length;
		int M = prices[0].length();
		
		int cost = 0;
		
		for (int i = 0; i < 7; i++) {
			int curr = Integer.MAX_VALUE;
			for (int j = 0; j < M; j++) {
				int now = 0;
				for (int k = i; k < D; k += 7) {
					now += decode(prices[k].charAt(j));
				}
				curr = Math.min(curr, now);
			}
			cost += curr;
		}
		
		return cost <= budget;
	}
	
	public int decode(char c) {
		if (c >= '0' && c <= '9') {
			return c - '0'; 
		} else if (c >= 'A' && c <= 'Z') {
			return c - 'A' + 10;
		} else {
			return c - 'a' + 36;
		}
	}
	
	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!
