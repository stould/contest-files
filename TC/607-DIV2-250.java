import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class BoundingBox {
	public int smallestArea(int[] X, int[] Y) {
		Arrays.sort(X);
		Arrays.sort(Y);
		
		int N = X.length;
		
		return (X[N - 1] - X[0]) * (Y[N - 1] - Y[0]);
	}
	
	public void debug(Object ... os) {
		System.out.println(Arrays.deepToString(os));
	}
}

//Powered by [KawigiEdit] 2.0!
