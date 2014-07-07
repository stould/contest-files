import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class WakingUpEasy {
	public int countAlarms(int[] volume, int S) {
		LinkedList<Integer> list = new LinkedList<Integer>();
		
		for (int i: volume) {
			list.add(i);
		}
		
		int ans = 0;
		
		for ( ; S > 0; ) {
			int f = list.poll();
			list.addLast(f);
			S -= f;
			ans += 1;
		}
		
		return ans;
	}	
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!
