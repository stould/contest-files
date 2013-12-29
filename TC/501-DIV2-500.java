import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class FoxPlayingGame {
	public double theMax(int nA, int nB, int paramA, int paramB) {
		int i;		

		double sa = paramA / 1000.0;
		double sb = paramB / 1000.0;
		
		double ans = nA * sa;
		double bff = ans;
		
		for (i = 0; i < nB; i++) {
			bff *= sb;
			ans = max(ans, bff);
		}
		
		
		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!
