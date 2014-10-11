import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class TheSimpleGame {
	public int count(int n, int[] x, int[] y) {
		int ans = 0;
		int L = x.length;
		
		for (int i = 0; i < L; i++) {
			int ul = x[i] + y[i] - 2;
			int ur = (n - x[i]) + y[i] - 1;
			int ll = x[i] + (n - y[i]) - 1;
			int lr = (n - x[i]) + (n - y[i]);
			
			ans += Math.min(ul, Math.min(ur, Math.min(ll, lr)));			
		}
		
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
