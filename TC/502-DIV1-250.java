import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class TheLotteryBothDivs {
	public double find(String[] good) {
		int N = good.length;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (i != j) {
				if (good[i].length() >= good[j].length() && !good[j].equals("") && !good[i].equals("")) {
					if (good[i].endsWith(good[j])) {
						good[i] = "";
					}
				}
			}
		}
		double[] p = new double[10];
		double ans = 0.0;
		
		p[0] = 1.0;

		for (int i = 1; i <= 9; i++) {
			p[i] = p[i - 1] * 10.0;
		}
		
		for (int i = 0; i < N; i++) {
			if (!good[i].equals("")) {
				debug(good[i]);
				debug(p[9 - good[i].length()]);
				ans += p[9 - good[i].length()];
			}
		}
		return ans / 1000000000.0;
	}	
	
	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!
