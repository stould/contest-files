import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class CirclesCountry {
	public static final double EPS = 1e-7;
	
	public int leastBorders(int[] X, int[] Y, int[] R, int x1, int y1, int x2, int y2) {
		int ans = 0;
		int N = X.length;
		
		boolean[] inA = new boolean[N];
		boolean[] inB = new boolean[N];
		
		for (int i = 0; i < N; i++) {
			if (inside(x1, y1, X[i], Y[i], R[i])) {
				ans += 1;
				inA[i] = true;
			}
			if (inside(x2, y2, X[i], Y[i], R[i])) {
				ans += 1;
				inB[i] = true;
			}
		}		
		
		for (int i = 0; i < N; i++) {
			if (inA[i] && inB[i]) {
				ans -= 2;
			}
		}
		
		return ans;	
	}
	
	boolean inside(int xa, int ya, int xc, int yc, int rc) {
		double dist = Math.hypot(xa - xc, ya - yc);
		
		if (dist + EPS <= rc) {
			return true;
		} else {
			return false;
		}
	}	
}

//Powered by [KawigiEdit] 2.0!
