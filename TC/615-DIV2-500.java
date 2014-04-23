import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class LongLongTripDiv2 {
	public String isAble(long D, int T, int B) {
		long L = 0, H = (long) ((double) D / (double) B) + 1, M;

		for ( ; L <= H; ) {
			M = (L + H) / 2;
			
			long p = M + Math.max(0, (D - M * B));			
			
			if (p == T) {
				return "Possible";
			} else if (p < T) {
				H = M - 1;
			} else {
				L = M + 1;
			}
		}
		return "Impossible";
	}
}

//Powered by [KawigiEdit] 2.0!