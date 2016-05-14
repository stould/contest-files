import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class EllysSocks {
    public int getDifference(int[] S, int P) {
        int N = S.length;
        Arrays.sort(S);
		
        long l = 0, h = 1000000000;
        int best = 0;
		
        while (l <= h) {
            long m = (l + h) / 2;
            int p = 0;
			
            for (int i = 1; i < N; i++) {
                if (S[i] - S[i - 1] <= m) {
                    p += 1;
                    i += 1;
                }	
            }
			
            if (p >= P) {
                best = (int) m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
		
        return best;
    }	
    public void debug(Object ... obj) {
        Arrays.deepToString(obj);
    }
}

//Powered by [KawigiEdit] 2.0!
