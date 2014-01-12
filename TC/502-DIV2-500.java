import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class TheLotteryBothDivs {
	public double find(String[] good) {
		int N = good.length;
		boolean[] used = new boolean[N];
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (good[i].equals(good[j])) {
					used[i] = true;
				}
			}
			for (int j = 0; j < N; j++) {
				if (good[i].length() > good[j].length() && good[i].substring(good[i].length() - good[j].length()).equals(good[j])) {
					used[i] = true;
				}
			}
		}
		
		double all = 1e9;
		double cur = 0.0;
		
		for (int i = 0; i < N; i++) if (!used[i]) {
			cur += (double) Math.pow(10.0, 9.0 - good[i].length());
		}
		
		return (double) cur / (double) all;		
	}	
	
	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!
